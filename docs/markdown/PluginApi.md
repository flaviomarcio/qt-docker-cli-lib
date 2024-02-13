# PluginApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**getPluginPrivileges**](PluginApi.md#getPluginPrivileges) | **GET** /plugins/privileges | Get plugin privileges
[**pluginCreate**](PluginApi.md#pluginCreate) | **POST** /plugins/create | Create a plugin
[**pluginDelete**](PluginApi.md#pluginDelete) | **DELETE** /plugins/{name} | Remove a plugin
[**pluginDisable**](PluginApi.md#pluginDisable) | **POST** /plugins/{name}/disable | Disable a plugin
[**pluginEnable**](PluginApi.md#pluginEnable) | **POST** /plugins/{name}/enable | Enable a plugin
[**pluginInspect**](PluginApi.md#pluginInspect) | **GET** /plugins/{name}/json | Inspect a plugin
[**pluginList**](PluginApi.md#pluginList) | **GET** /plugins | List plugins
[**pluginPull**](PluginApi.md#pluginPull) | **POST** /plugins/pull | Install a plugin
[**pluginPush**](PluginApi.md#pluginPush) | **POST** /plugins/{name}/push | Push a plugin
[**pluginSet**](PluginApi.md#pluginSet) | **POST** /plugins/{name}/set | Configure a plugin
[**pluginUpgrade**](PluginApi.md#pluginUpgrade) | **POST** /plugins/{name}/upgrade | Upgrade a plugin


## **getPluginPrivileges**

Get plugin privileges

### Example
```bash
 getPluginPrivileges  remote=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **remote** | **string** | The name of the plugin. The ':latest' tag is optional, and is the
default if omitted. |

### Return type

[**array[PluginPrivilege]**](PluginPrivilege.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **pluginCreate**

Create a plugin

### Example
```bash
 pluginCreate  name=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | The name of the plugin. The ':latest' tag is optional, and is the
default if omitted. |
 **tarContext** | **binary** | Path to tar containing plugin rootfs and manifest | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/x-tar
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **pluginDelete**

Remove a plugin

### Example
```bash
 pluginDelete name=value  force=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | The name of the plugin. The ':latest' tag is optional, and is the
default if omitted. |
 **force** | **boolean** | Disable the plugin before removing. This may result in issues if the
plugin is in use by a container. | [optional] [default to false]

### Return type

[**Plugin**](Plugin.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **pluginDisable**

Disable a plugin

### Example
```bash
 pluginDisable name=value  force=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | The name of the plugin. The ':latest' tag is optional, and is the
default if omitted. |
 **force** | **boolean** | Force disable a plugin even if still in use. | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **pluginEnable**

Enable a plugin

### Example
```bash
 pluginEnable name=value  timeout=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | The name of the plugin. The ':latest' tag is optional, and is the
default if omitted. |
 **timeout** | **integer** | Set the HTTP client timeout (in seconds) | [optional] [default to 0]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **pluginInspect**

Inspect a plugin

### Example
```bash
 pluginInspect name=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | The name of the plugin. The ':latest' tag is optional, and is the
default if omitted. |

### Return type

[**Plugin**](Plugin.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **pluginList**

List plugins

Returns information about installed plugins.

### Example
```bash
 pluginList  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **filters** | **string** | A JSON encoded value of the filters (a 'map[string][]string') to
process on the plugin list.

Available filters:

- 'capability=<capability name>'
- 'enable=<true>|<false>' | [optional]

### Return type

[**array[Plugin]**](Plugin.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **pluginPull**

Install a plugin

Pulls and installs a plugin. After the plugin is installed, it can be
enabled using the ['POST /plugins/{name}/enable' endpoint](#operation/PostPluginsEnable).

### Example
```bash
 pluginPull  remote=value  name=value X-Registry-Auth:value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **remote** | **string** | Remote reference for plugin to install.

The ':latest' tag is optional, and is used as the default if omitted. |
 **name** | **string** | Local name for the pulled plugin.

The ':latest' tag is optional, and is used as the default if omitted. | [optional]
 **xRegistryAuth** | **string** | A base64url-encoded auth configuration to use when pulling a plugin
from a registry.

Refer to the [authentication section](#section/Authentication) for
details. | [optional]
 **body** | [**array[PluginPrivilege]**](PluginPrivilege.md) |  | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **pluginPush**

Push a plugin

Push a plugin to the registry.

### Example
```bash
 pluginPush name=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | The name of the plugin. The ':latest' tag is optional, and is the
default if omitted. |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **pluginSet**

Configure a plugin

### Example
```bash
 pluginSet name=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | The name of the plugin. The ':latest' tag is optional, and is the
default if omitted. |
 **body** | **array[string]** |  | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **pluginUpgrade**

Upgrade a plugin

### Example
```bash
 pluginUpgrade name=value  remote=value X-Registry-Auth:value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | The name of the plugin. The ':latest' tag is optional, and is the
default if omitted. |
 **remote** | **string** | Remote reference to upgrade to.

The ':latest' tag is optional, and is used as the default if omitted. |
 **xRegistryAuth** | **string** | A base64url-encoded auth configuration to use when pulling a plugin
from a registry.

Refer to the [authentication section](#section/Authentication) for
details. | [optional]
 **body** | [**array[PluginPrivilege]**](PluginPrivilege.md) |  | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

