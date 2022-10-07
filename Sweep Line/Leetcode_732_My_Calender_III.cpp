// Explanation
// We use a map count, use time points as the key.
// If count[t] means that,
// from the time point t,
// we have count[t] events at the same time,
// until the next time point after t.
//
// Next let me explain the line of map operation
// count.emplace(t, (--count.lower_bound(t))->second).
//
// If the map count already has the time point t as the key,
// no insertion happen and the map doesn't change.
// count.emplace(t, value) will return a pair of <iterator, false>
//
// If the map count doesn't contain the time point t as the key,
// count.emplace(t, value) will return a pair of <iterator, true>
//
// count.upper_bound(s) will return the first time itertor after the time point t.
// --count.upper_bound(s) will get the first time itertor before the time point t.
// (--count.upper_bound(s))->second will get the event number at the time point t.
// We insert this value to count[t],
// count.emplace(t, value) will return a pair of <iterator, true>
//
// Now we need to do is,
// iterate and increment all the time points in the time window start and end.
//
//
// Complexity
// The total runtime is about 40ms, beats 95%.
// book(int s, int e) iterates only time points between the start and end.
// This halp reduce half runtme, compared with the solution iteration on whole map.

// Code:-
class MyCalendarThree
{
public:
    map<int, int> mp;
    MyCalendarThree()
    {
        mp.clear();
    }

    int book(int start, int end)
    {
        map<int, int> count = {{-1, 0}};
        int res = 0;
        auto start = count.emplace(s, (--count.upper_bound(s))->second);
        auto end = count.emplace(e, (--count.upper_bound(e))->second);
        for (auto i = start.first; i != end.first; ++i)
            res = max(res, ++(i->second));
        return res;
    }
};
