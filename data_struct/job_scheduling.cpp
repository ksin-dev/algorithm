#include <iostream>
#include <list>
#include <vector>
#include <numeric>

struct Job
{
  int id;
  int start_time;
  int end_time;

  Job(int id, int start_time, int end_time) : id(id), start_time(start_time), end_time(end_time)
  {
  }

  inline bool operator<(const Job &target) const
  {
    if (this->end_time == target.end_time)
      return this->start_time < target.start_time;
    return (this->end_time < target.end_time);
  }

  friend std::ostream &operator<<(std::ostream &os, Job &job);
};

void fill_job(std::list<Job> &jobs)
{
  if (jobs.size() == 0)
    return;
  auto begin = jobs.front();
  jobs.pop_front();

  while (jobs.size() > 0)
  {
    auto front = jobs.front();
    if (front.start_time < begin.end_time || front.end_time <= begin.end_time)
      jobs.pop_front();
    else
      break;
  }

  fill_job(jobs);
  jobs.push_front(begin);
}

std::ostream &operator<<(std::ostream &os, Job &job)
{
  os << "[" << job.id << "] " << job.start_time << "->" << job.end_time << "\t|";

  for (auto i = 0; i < 20; i++)
  {
    if (i > job.start_time && i <= job.end_time)
      os << "*";
    else
      os << " ";
  }
  os << "|" << std::endl;
  return os;
}

template <typename T>
void print(std::list<T> &v)
{
  for (auto &i : v)
    std::cout << i;
}

int main(int argc, char *argv[])
{
  std::vector<int> start_times{5, 6, 16, 7, 9, 10, 6, 2, 10, 4};
  std::vector<int> end_times{9, 20, 19, 10, 19, 19, 12, 17, 13, 7};
  std::list<Job> jobs;

  for (int i = 0; i < start_times.size(); i++)
    jobs.push_back(Job(i, start_times[i], end_times[i]));

  std::cout << "[전체 작업]" << std::endl;
  print<Job>(jobs);

  jobs.sort();
  fill_job(jobs);
  std::cout
      << "[스케줄 조정 작업]" << std::endl;
  print<Job>(jobs);

  return 0;
}