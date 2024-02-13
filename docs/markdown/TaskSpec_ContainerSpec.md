# TaskSpec_ContainerSpec

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Image** | **string** |  | [optional] [default to null]
**Labels** | **map[String, string]** |  | [optional] [default to null]
**Command** | **array[string]** |  | [optional] [default to null]
**Args** | **array[string]** |  | [optional] [default to null]
**Hostname** | **string** |  | [optional] [default to null]
**Env** | **array[string]** |  | [optional] [default to null]
**Dir** | **string** |  | [optional] [default to null]
**User** | **string** |  | [optional] [default to null]
**Groups** | **array[string]** |  | [optional] [default to null]
**Privileges** | [**TaskSpec_ContainerSpec_Privileges**](TaskSpec_ContainerSpec_Privileges.md) |  | [optional] [default to null]
**TTY** | **boolean** |  | [optional] [default to null]
**OpenStdin** | **boolean** |  | [optional] [default to null]
**ReadOnly** | **boolean** |  | [optional] [default to null]
**Mounts** | [**array[Mount]**](Mount.md) |  | [optional] [default to null]
**StopSignal** | **string** |  | [optional] [default to null]
**StopGracePeriod** | **integer** |  | [optional] [default to null]
**HealthCheck** | [**HealthConfig**](HealthConfig.md) |  | [optional] [default to null]
**Hosts** | **array[string]** |  | [optional] [default to null]
**DNSConfig** | [**TaskSpec_ContainerSpec_DNSConfig**](TaskSpec_ContainerSpec_DNSConfig.md) |  | [optional] [default to null]
**Secrets** | [**array[TaskSpec_ContainerSpec_Secrets]**](TaskSpec_ContainerSpec_Secrets.md) |  | [optional] [default to null]
**Configs** | [**array[TaskSpec_ContainerSpec_Configs]**](TaskSpec_ContainerSpec_Configs.md) |  | [optional] [default to null]
**Isolation** | **string** |  | [optional] [default to null]
**Init** | **boolean** |  | [optional] [default to null]
**Sysctls** | **map[String, string]** |  | [optional] [default to null]
**CapabilityAdd** | **array[string]** |  | [optional] [default to null]
**CapabilityDrop** | **array[string]** |  | [optional] [default to null]
**Ulimits** | [**array[Resources_Ulimits]**](Resources_Ulimits.md) |  | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


