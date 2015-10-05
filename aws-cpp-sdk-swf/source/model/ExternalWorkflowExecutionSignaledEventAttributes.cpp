/*
* Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/swf/model/ExternalWorkflowExecutionSignaledEventAttributes.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::SWF::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

ExternalWorkflowExecutionSignaledEventAttributes::ExternalWorkflowExecutionSignaledEventAttributes() : 
    m_workflowExecutionHasBeenSet(false),
    m_initiatedEventId(0),
    m_initiatedEventIdHasBeenSet(false)
{
}

ExternalWorkflowExecutionSignaledEventAttributes::ExternalWorkflowExecutionSignaledEventAttributes(const JsonValue& jsonValue) : 
    m_workflowExecutionHasBeenSet(false),
    m_initiatedEventId(0),
    m_initiatedEventIdHasBeenSet(false)
{
  *this = jsonValue;
}

ExternalWorkflowExecutionSignaledEventAttributes& ExternalWorkflowExecutionSignaledEventAttributes::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("workflowExecution"))
  {
    m_workflowExecution = jsonValue.GetObject("workflowExecution");

    m_workflowExecutionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("initiatedEventId"))
  {
    m_initiatedEventId = jsonValue.GetInt64("initiatedEventId");

    m_initiatedEventIdHasBeenSet = true;
  }

  return *this;
}

JsonValue ExternalWorkflowExecutionSignaledEventAttributes::Jsonize() const
{
  JsonValue payload;

  if(m_workflowExecutionHasBeenSet)
  {
   payload.WithObject("workflowExecution", m_workflowExecution.Jsonize());

  }

  if(m_initiatedEventIdHasBeenSet)
  {
   payload.WithInt64("initiatedEventId", m_initiatedEventId);

  }

  return std::move(payload);
}