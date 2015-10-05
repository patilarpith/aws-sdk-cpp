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
#include <aws/ec2/model/DescribeInstanceStatusResponse.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>

#include <utility>

using namespace Aws::EC2::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;
using namespace Aws;

DescribeInstanceStatusResponse::DescribeInstanceStatusResponse()
{
}

DescribeInstanceStatusResponse::DescribeInstanceStatusResponse(const AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

DescribeInstanceStatusResponse& DescribeInstanceStatusResponse::operator =(const AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode;
  if (rootNode.GetName() != "DescribeInstanceStatusResponse")
  {
    resultNode = rootNode.FirstChild("DescribeInstanceStatusResponse");
  }

  if(!resultNode.IsNull())
  {
    XmlNode instanceStatusesNode = resultNode.FirstChild("InstanceStatuses");
    if(!instanceStatusesNode.IsNull())
    {
      XmlNode instanceStatusesMember = instanceStatusesNode.FirstChild("item");
      while(!instanceStatusesMember.IsNull())
      {
        m_instanceStatuses.push_back(instanceStatusesMember);
        instanceStatusesMember = instanceStatusesMember.NextNode("item");
      }

    }
    XmlNode nextTokenNode = resultNode.FirstChild("nextToken");
    if(!nextTokenNode.IsNull())
    {
      m_nextToken = StringUtils::Trim(nextTokenNode.GetText().c_str());
    }
  }

  XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
  m_responseMetadata = responseMetadataNode;

  return *this;
}
