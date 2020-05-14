#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <algorithm>
#include <tuple>
using namespace std;
using ull =  unsigned long long;
// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    TaskStatus Next(TaskStatus status){
        return static_cast<TaskStatus>(static_cast<int>(status)+1);
    }
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        return razrab.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person){
        //TasksInfo a;
            ++razrab[person][TaskStatus::NEW];
        }


    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count){
        TasksInfo update_problems, noupdate_problems;
        TasksInfo& task = razrab[person];
        for(TaskStatus status = TaskStatus::NEW; status!=TaskStatus::DONE; status = Next(status)){
            update_problems[Next(status)] = min(task_count, task[status]);
            task_count -= update_problems[Next(status)];
        }
        for(TaskStatus status = TaskStatus::NEW; status!=TaskStatus::DONE; status = Next(status)) {
        noupdate_problems[status] = task[status]-update_problems[Next(status)];
        task[status] +=update_problems[status]- update_problems[Next(status)];
        }
task[TaskStatus::DONE] +=update_problems[TaskStatus::DONE];
        EraseofZero(update_problems);
        EraseofZero(noupdate_problems);
        return {update_problems, noupdate_problems};
    }

    void EraseofZero(TasksInfo& tasksinfo){
        vector<TaskStatus> status;
        for(const auto & value: tasksinfo){
            if(value.second == 0){
                status.push_back(value.first);
            }}
        for(const auto& w: status){
            tasksinfo.erase(w);
        }
    }

private:
    map<string, TasksInfo>razrab;
};



// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}

