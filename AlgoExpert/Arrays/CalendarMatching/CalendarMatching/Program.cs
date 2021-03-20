using System;
using System.Collections.Generic;

namespace CalendarMatching
{
    public class Meeting
    {
        public string StartTime { get; set; }

        public string EndTime { get; set; }

        public int Start { get; set; }

        public int End { get; set; }

        public Meeting(string startTime, string endTime)
        {
            this.StartTime = startTime;
            this.EndTime = endTime;
        }

        public Meeting(int start, int end)
        {
            this.Start = start;
            this.End = end;
        }

        public override string ToString()
        {
            return $"{this.StartTime} - {this.EndTime}";
        }
    }

    public class Calendar
    {
        public List<Meeting> GetMatchingAvailabilities(Meeting dailyBounds1, Meeting dailyBounds2, List<Meeting> calendar1, List<Meeting> calendar2, int meetingDuration)
        {
            List<Meeting> updatedCalendar1 = this.UpdateCalendar(calendar1, dailyBounds1);
            List<Meeting> updatedCalendar2 = this.UpdateCalendar(calendar2, dailyBounds2);
            List<Meeting> mergedCalendar = this.MergeCalendars(updatedCalendar1, updatedCalendar2);
            List<Meeting> flattenedCalendar = this.FlattenCalendar(mergedCalendar);
            return this.MatchingAvailabilities(flattenedCalendar, meetingDuration);
        }

        List<Meeting> UpdateCalendar(List<Meeting> calendar, Meeting dailyBounds)
        {
            calendar.Insert(0, new Meeting("0:00", dailyBounds.StartTime));
            calendar.Add(new Meeting(dailyBounds.EndTime, "23:59"));
            for (int i = 0; i < calendar.Count; i++)
                calendar[i] = this.TimeToMinutes(calendar[i]);

            return calendar;
        }

        Meeting TimeToMinutes(Meeting calendar)
        {
            string[] starttime = calendar.StartTime.Split(":");
            string[] endtime = calendar.EndTime.Split(":");

            calendar.Start = Convert.ToInt32(starttime[0]) * 60 + Convert.ToInt32(starttime[1]);
            calendar.End = Convert.ToInt32(endtime[0]) * 60 + Convert.ToInt32(endtime[1]);

            return calendar;
        }

        List<Meeting> MergeCalendars(List<Meeting> calendar1, List<Meeting> calendar2)
        {
            List<Meeting> mergedCalendar = new List<Meeting>();
            int i = 0, j = 0;
            while (i < calendar1.Count && j < calendar2.Count)
            {
                if (calendar1[i].Start < calendar2[i].Start)
                    mergedCalendar.Add(calendar1[i++]);
                else
                    mergedCalendar.Add(calendar2[j++]);
            }

            while (i < calendar1.Count)
                mergedCalendar.Add(calendar1[i++]);

            while (j < calendar2.Count)
                mergedCalendar.Add(calendar2[j++]);

            return mergedCalendar;
        }

        List<Meeting> FlattenCalendar(List<Meeting> calendar)
        {
            List<Meeting> flattenedCalendar = new List<Meeting>() { calendar[0] };
            for (int i = 1; i < calendar.Count; i++)
            {
                int lastIndex = flattenedCalendar.Count - 1;
                if (flattenedCalendar[lastIndex].End >= calendar[i].Start)
                    flattenedCalendar[lastIndex].End = Math.Max(flattenedCalendar[lastIndex].End, calendar[i].End);
                else flattenedCalendar.Add(calendar[i]);
            }

            return flattenedCalendar;
        }

        List<Meeting> MatchingAvailabilities(List<Meeting> calendar, int meetingDuration)
        {
            List<Meeting> matchingAvailabilities = new List<Meeting>();
            for (int i = 1; i < calendar.Count; i++)
            {
                if (calendar[i].Start - calendar[i - 1].End >= meetingDuration)
                    matchingAvailabilities.Add(new Meeting(calendar[i - 1].End, calendar[i].Start));
            }

            for (int i = 0; i < matchingAvailabilities.Count; i++)
            {
                matchingAvailabilities[i].StartTime = this.MinutesToTime(matchingAvailabilities[i].Start);
                matchingAvailabilities[i].EndTime = this.MinutesToTime(matchingAvailabilities[i].End);
            }

            return matchingAvailabilities;
        }

        string MinutesToTime(int minutes)
        {
            int hours = Convert.ToInt32(Math.Floor(minutes / 60.0)), _minutes = minutes % 60;
            string minutesString = _minutes < 10 ? "0" + Convert.ToString(_minutes) : Convert.ToString(_minutes);
            return Convert.ToString(hours) + ":" + minutesString;
        }
    }

    public class Program
    {
        public static void Main(string[] args)
        {
            Meeting dailybounds1 = new Meeting("9:00", "20:00");
            Meeting dailybounds2 = new Meeting("10:00", "18:30");

            List<Meeting> calendar1 = new List<Meeting>
            {
                new Meeting("9:00", "10:30"),
                new Meeting("12:00", "13:00"),
                new Meeting("16:00", "18:00")
            };

            foreach (Meeting meeting in calendar1)
                Console.WriteLine(meeting.ToString());
            Console.WriteLine();

            List<Meeting> calendar2 = new List<Meeting>
            {
                new Meeting("10:00", "11:30"),
                new Meeting("12:30", "14:30"),
                new Meeting("14:30", "15:00"),
                new Meeting("16:00", "17:00")
            };

            foreach (Meeting meeting in calendar2)
                Console.WriteLine(meeting.ToString());
            Console.WriteLine();

            Calendar calendar = new Calendar();
            List<Meeting> matchingAvailabilities = calendar.GetMatchingAvailabilities(dailybounds1, dailybounds2, calendar1, calendar2, 30);

            Console.WriteLine("Available meeting times");
            foreach (Meeting meeting in matchingAvailabilities)
                Console.WriteLine(meeting.ToString());
        }
    }
}