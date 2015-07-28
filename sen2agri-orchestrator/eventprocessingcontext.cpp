#include <QDir>
#include <QFile>
#include <QString>

#include "eventprocessingcontext.hpp"
#include "dbus_future_utils.hpp"

EventProcessingContext::EventProcessingContext(
    OrgEsaSen2agriPersistenceManagerInterface &persistenceManagerClient)
    : persistenceManagerClient(persistenceManagerClient)
{
}

JobConfigurationParameterValueList
EventProcessingContext::GetJobConfigurationParameters(int jobId, QString prefix)
{
    return WaitForResponseAndThrow(
        persistenceManagerClient.GetJobConfigurationParameters(jobId, prefix));
}

int EventProcessingContext::SubmitTask(const NewTask &task)
{
    auto taskId = WaitForResponseAndThrow(persistenceManagerClient.SubmitTask(task));

    const auto &path = GetOutputPath(task.jobId, taskId);
    QDir::root().mkpath(path);

    return taskId;
}

void EventProcessingContext::SubmitSteps(const NewStepList &steps)
{
    WaitForResponseAndThrow(persistenceManagerClient.SubmitSteps(steps));
}

void EventProcessingContext::MarkJobPaused(int jobId)
{
    WaitForResponseAndThrow(persistenceManagerClient.MarkJobPaused(jobId));
}

void EventProcessingContext::MarkJobResumed(int jobId)
{
    WaitForResponseAndThrow(persistenceManagerClient.MarkJobResumed(jobId));
}

void EventProcessingContext::MarkJobCancelled(int jobId)
{
    WaitForResponseAndThrow(persistenceManagerClient.MarkJobCancelled(jobId));
}

void EventProcessingContext::MarkJobFinished(int jobId)
{
    WaitForResponseAndThrow(persistenceManagerClient.MarkJobFinished(jobId));
}

void EventProcessingContext::MarkJobFailed(int jobId)
{
    WaitForResponseAndThrow(persistenceManagerClient.MarkJobFailed(jobId));
}

void EventProcessingContext::MarkJobNeedsInput(int jobId)
{
    WaitForResponseAndThrow(persistenceManagerClient.MarkJobNeedsInput(jobId));
}

TaskIdList EventProcessingContext::GetJobTasksByStatus(int jobId,
                                                       const ExecutionStatusList &statusList)
{
    return WaitForResponseAndThrow(persistenceManagerClient.GetJobTasksByStatus(jobId, statusList));
}

UnprocessedEventList EventProcessingContext::GetNewEvents()
{
    return WaitForResponseAndThrow(persistenceManagerClient.GetNewEvents());
}

void EventProcessingContext::MarkEventProcessingStarted(int eventId)
{
    WaitForResponseAndThrow(persistenceManagerClient.MarkEventProcessingStarted(eventId));
}

void EventProcessingContext::MarkEventProcessingComplete(int eventId)
{
    WaitForResponseAndThrow(persistenceManagerClient.MarkEventProcessingComplete(eventId));
}

int EventProcessingContext::InsertProduct(const NewProduct &product)
{
    return WaitForResponseAndThrow(persistenceManagerClient.InsertProduct(product));
}

QStringList EventProcessingContext::GetProductFiles(const QString &path,
                                                    const QString &pattern) const
{
    return QDir(path).entryList(QStringList() << pattern, QDir::Files);
}

QString EventProcessingContext::GetOutputPath(int jobId, int taskId)
{
    return GetScratchPath(jobId)
        .replace(QLatin1String("{job_id}"), QString::number(jobId))
        .replace(QLatin1String("{task_id}"), QString::number(taskId));
}

QString EventProcessingContext::GetScratchPath(int jobId)
{
    const auto &parameters =
        WaitForResponseAndThrow(persistenceManagerClient.GetJobConfigurationParameters(
            jobId, QStringLiteral("general.scratch-path")));

    if (parameters.empty()) {
        throw std::runtime_error("Please configure the \"general.scratch-path\" parameter with the "
                                 "temporary file path");
    }

    Q_ASSERT(parameters.size() == 1);

    return QDir::cleanPath(parameters.front().value) + QDir::separator();
}
