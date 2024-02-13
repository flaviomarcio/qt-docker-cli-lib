# TaskApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**taskInspect**](TaskApi.md#taskInspect) | **GET** /tasks/{id} | Inspect a task
[**taskList**](TaskApi.md#taskList) | **GET** /tasks | List tasks
[**taskLogs**](TaskApi.md#taskLogs) | **GET** /tasks/{id}/logs | Get task logs


## **taskInspect**

Inspect a task

### Example
```bash
 taskInspect id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID of the task |

### Return type

[**Task**](Task.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **taskList**

List tasks

### Example
```bash
 taskList  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **filters** | **string** | A JSON encoded value of the filters (a 'map[string][]string') to
process on the tasks list.

Available filters:

- 'desired-state=(running | shutdown | accepted)'
- 'id=<task id>'
- 'label=key' or 'label=\"key=value\"'
- 'name=<task name>'
- 'node=<node id or name>'
- 'service=<service name>' | [optional]

### Return type

[**array[Task]**](Task.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **taskLogs**

Get task logs

Get 'stdout' and 'stderr' logs from a task.
See also ['/containers/{id}/logs'](#operation/ContainerLogs).

**Note**: This endpoint works only for services with the 'local',
'json-file' or 'journald' logging drivers.

### Example
```bash
 taskLogs id=value  details=value  follow=value  stdout=value  stderr=value  since=value  timestamps=value  tail=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID of the task |
 **details** | **boolean** | Show task context and extra details provided to logs. | [optional] [default to false]
 **follow** | **boolean** | Keep connection after returning logs. | [optional] [default to false]
 **stdout** | **boolean** | Return logs from 'stdout' | [optional] [default to false]
 **stderr** | **boolean** | Return logs from 'stderr' | [optional] [default to false]
 **since** | **integer** | Only return logs since this time, as a UNIX timestamp | [optional] [default to 0]
 **timestamps** | **boolean** | Add timestamps to every log line | [optional] [default to false]
 **tail** | **string** | Only return this number of log lines from the end of the logs.
Specify as an integer or 'all' to output all log lines. | [optional] [default to all]

### Return type

**binary**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/vnd.docker.raw-stream, application/vnd.docker.multiplexed-stream

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

