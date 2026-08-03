/* splits the day of the year into its equivalent month and day */
void split_date(int day_of_year, int year, int *month, int *day)
{
    int i, months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        months[1] = 29;

    i = 0;
    while (day_of_year > months[i])
        day_of_year -= months[i++];
    *month = i + 1;
    *day = day_of_year;
}
