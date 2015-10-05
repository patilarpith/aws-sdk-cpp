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
#include <aws/ec2/model/CancelSpotFleetRequestsResponse.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>

#include <utility>

using namespace Aws::EC2::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;
using namespace Aws;

CancelSpotFleetRequestsResponse::CancelSpotFleetRequestsResponse()
{
}

CancelSpotFleetRequestsResponse::CancelSpotFleetRequestsResponse(const AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

CancelSpotFleetRequestsResponse& CancelSpotFleetRequestsResponse::operator =(const AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode;
  if (rootNode.GetName() != "CancelSpotFleetRequestsResponse")
  {
    resultNode = rootNode.FirstChild("CancelSpotFleetRequestsResponse");
  }

  if(!resultNode.IsNull())
  {
    XmlNode unsuccessfulFleetRequestsNode = resultNode.FirstChild("UnsuccessfulFleetRequests");
    if(!unsuccessfulFleetRequestsNode.IsNull())
    {
      XmlNode unsuccessfulFleetRequestsMember = unsuccessfulFleetRequestsNode.FirstChild("item");
      while(!unsuccessfulFleetRequestsMember.IsNull())
      {
        m_unsuccessfulFleetRequests.push_back(unsuccessfulFleetRequestsMember);
        unsuccessfulFleetRequestsMember = unsuccessfulFleetRequestsMember.NextNode("item");
      }

    }
    XmlNode successfulFleetRequestsNode = resultNode.FirstChild("SuccessfulFleetRequests");
    if(!successfulFleetRequestsNode.IsNull())
    {
      XmlNode successfulFleetRequestsMember = successfulFleetRequestsNode.FirstChild("item");
      while(!successfulFleetRequestsMember.IsNull())
      {
        m_successfulFleetRequests.push_back(successfulFleetRequestsMember);
        successfulFleetRequestsMember = successfulFleetRequestsMember.NextNode("item");
      }

    }
  }

  XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
  m_responseMetadata = responseMetadataNode;

  return *this;
}
