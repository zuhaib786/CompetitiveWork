#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define mp make_pair

using pi = pair<int, int>;
using vi = vector<int>;

int N, D, M;

// test if it is possible to finish the jobs using given # of machines
// return: first: possible or not, second: if possible, the schedule for the jobs
pair<bool, vector<vi>> isFeasible(const vector<pi> &jobs, int machineCount)
{
	vector<vi> schedule(N);
	int reqNum = 0;
	// we simulate from day 1 until the last day N
	// we move to the next day if all the machines are used or
	// there is no more job requests left on or before this day
	for (int day = 1; day <= N; day++)
	{
		for (int j = 0; j < machineCount; j++)
		{
			// if all jobs before and on this day are finished,
			// we can go to the next day, even if there are usable machines left
			// we can determine that since the vector jobs is sorted
			if (jobs[reqNum].first > day)
				break;
			// if the current date is before the deadline for the job
			// we can add this job to the schedule and move to the next job request
			if (jobs[reqNum].first + D >= day)
				schedule[day - 1].push_back(jobs[reqNum++].second);
			// otherwise, it is not feasible due to deadline
			else
				return mp(false, schedule);

			// if we have processed all the requests, we have found a feasible sol
			if (reqNum == M)
				return mp(true, schedule);
		}
	}
	// if not all the requests can be processed within the given N days,
	// then it is not feasible
	return mp(false, schedule);
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> D >> M;
	vector<pi> jobs(M);
	for (int i = 0; i < M; i++)
	{
		int day;
		cin >> day;
		// first: request date, second: index [1..M]
		jobs[i] = mp(day, i + 1);
	}
	// we sort the jobs by the request date in ascending order
	// sothat we can test them using isFeasible() in linear time whether they
	// can be done in given time using a certain amount of machines
	sort(all(jobs));

	vector<vi> result;
	// binary search on the number of machines for the minimum possible solution
	// left and right bound, l and r
	int l = 1, r = M;
	while (l < r)
	{
		int machineNum = (l + r) / 2;
		// test if the jobs would finish within the deadline
		// using the current # of machines, machineNum
		pair<bool, vector<vi>> curResult = isFeasible(jobs, machineNum);
		// if it's possible, we set the right bound as the tested machine number
		// and save the current schedule
		if (curResult.first)
		{
			r = machineNum;
			result = curResult.second;
		}
		// otherwise, we set the left bound to be the tested number + 1
		// and test the next machineNum again
		else
			l = machineNum + 1;
	}

	cout << l << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int &idx : result[i])
			cout << idx << " ";
		cout << 0 << "\n";
	}
}