/*
 * Copyright (C) 2005-2010 Erik Nilsson, software on versionstudio point com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef guard_jsdatabasemanager_h
#define guard_jsdatabasemanager_h

#include <jsapi.h>

/**
* JsDatabaseManager.
* JavaScript representation of the DatabaseManager class.
*/
class JsDatabaseManager
{
public:
	/**
	* Initialize the js class and makes it accessible in the context.
	* @param cx the context from which to derive runtime information
	* @param obj the global object to use for initializing the class
	* @return the object that is the prototype for the newly initialized class
	*/
	static JSObject* jsInit(JSContext *cx,JSObject *obj);

	/**
	* Create a new instance of the class.
	* @param cx the context where the instance should be created
	* @param obj the context object supplied at runtime
	* @return the new instance object
	*/
	static JSObject* jsInstance(JSContext *cx,JSObject *obj);
	
	/**
	* Get the js class instance.
	* @return the js class instance
	*/
	static JSClass *getJsClass() { 
		return &m_jsClass; 
	}

	/**
	* Get a database connection.
	*/
	static JSBool getConnection(JSContext *cx,JSObject *obj,uintN argc,jsval *argv,jsval *rval);

	/**
	* Release a database connection.
	*/
	static JSBool releaseConnection(JSContext *cx,JSObject *obj,uintN argc,jsval *argv,jsval *rval);

private:
	static JSClass m_jsClass;
	static JSFunctionSpec m_jsFunctionSpec[];
};

#endif
