#include "Parameter.h"
#include "Node.h"
/*
Parameter::Parameter():m_paramType(INPUT_PARAM)
{

}*/
Parameter::Parameter(std::string name, Type type, ParamType paramType):
	m_name(name), m_type(type), m_paramType(paramType)
{
}


Parameter::~Parameter()
{
}

bool Parameter::IsCompatible(std::shared_ptr<Parameter> other)
{
	return ( GetParamType() != other->GetParamType() ) && ( GetType().CompatibleWith(other->GetType()) );
}

void Parameter::AddLink(std::shared_ptr<Parameter> dstParam)
{
	// Link to the node
	m_links.push_back(dstParam);
	// Set the the node to be the data source only if this param is the input
	if(m_paramType == INPUT_PARAM)
		m_data = dstParam->GetData();
}