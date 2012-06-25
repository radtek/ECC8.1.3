/* soapClient.cpp
   Generated by gSOAP 2.7.12 from D:\program\huaWei\soap\soap\huaWei.h
   Copyright(C) 2000-2008, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/
#include "soapH.h"

SOAP_SOURCE_STAMP("@(#) soapClient.cpp ver 2.7.12 2009-05-15 01:26:06 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__SetParameterValues(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__SetParameterValues *ns1__SetParameterValues, _ns1__SetParameterValuesResponse *ns1__SetParameterValuesResponse)
{	struct __ns1__SetParameterValues soap_tmp___ns1__SetParameterValues;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost:8080/cwmp";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__SetParameterValues.ns1__SetParameterValues = ns1__SetParameterValues;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__SetParameterValues(soap, &soap_tmp___ns1__SetParameterValues);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__SetParameterValues(soap, &soap_tmp___ns1__SetParameterValues, "-ns1:SetParameterValues", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__SetParameterValues(soap, &soap_tmp___ns1__SetParameterValues, "-ns1:SetParameterValues", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__SetParameterValuesResponse)
		return soap_closesock(soap);
	ns1__SetParameterValuesResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__SetParameterValuesResponse->soap_get(soap, "ns1:SetParameterValuesResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetParameterValues(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetParameterValues *ns1__GetParameterValues, _ns1__GetParameterValuesResponse *ns1__GetParameterValuesResponse)
{	struct __ns1__GetParameterValues soap_tmp___ns1__GetParameterValues;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost:8080/cwmp";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetParameterValues.ns1__GetParameterValues = ns1__GetParameterValues;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__GetParameterValues(soap, &soap_tmp___ns1__GetParameterValues);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetParameterValues(soap, &soap_tmp___ns1__GetParameterValues, "-ns1:GetParameterValues", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetParameterValues(soap, &soap_tmp___ns1__GetParameterValues, "-ns1:GetParameterValues", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__GetParameterValuesResponse)
		return soap_closesock(soap);
	ns1__GetParameterValuesResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__GetParameterValuesResponse->soap_get(soap, "ns1:GetParameterValuesResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__SetParameterAttributes(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__SetParameterAttributes *ns1__SetParameterAttributes, _ns1__SetParameterAttributesResponse *ns1__SetParameterAttributesResponse)
{	struct __ns1__SetParameterAttributes soap_tmp___ns1__SetParameterAttributes;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost:8080/cwmp";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__SetParameterAttributes.ns1__SetParameterAttributes = ns1__SetParameterAttributes;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__SetParameterAttributes(soap, &soap_tmp___ns1__SetParameterAttributes);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__SetParameterAttributes(soap, &soap_tmp___ns1__SetParameterAttributes, "-ns1:SetParameterAttributes", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__SetParameterAttributes(soap, &soap_tmp___ns1__SetParameterAttributes, "-ns1:SetParameterAttributes", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__SetParameterAttributesResponse)
		return soap_closesock(soap);
	ns1__SetParameterAttributesResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__SetParameterAttributesResponse->soap_get(soap, "ns1:SetParameterAttributesResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetParameterAttributes(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetParameterAttributes *ns1__GetParameterAttributes, _ns1__GetParameterAttributesResponse *ns1__GetParameterAttributesResponse)
{	struct __ns1__GetParameterAttributes soap_tmp___ns1__GetParameterAttributes;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost:8080/cwmp";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetParameterAttributes.ns1__GetParameterAttributes = ns1__GetParameterAttributes;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__GetParameterAttributes(soap, &soap_tmp___ns1__GetParameterAttributes);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetParameterAttributes(soap, &soap_tmp___ns1__GetParameterAttributes, "-ns1:GetParameterAttributes", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetParameterAttributes(soap, &soap_tmp___ns1__GetParameterAttributes, "-ns1:GetParameterAttributes", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__GetParameterAttributesResponse)
		return soap_closesock(soap);
	ns1__GetParameterAttributesResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__GetParameterAttributesResponse->soap_get(soap, "ns1:GetParameterAttributesResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

/* End of soapClient.cpp */
