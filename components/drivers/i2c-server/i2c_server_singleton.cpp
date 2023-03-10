/*
 * Copyright (c) 2022 Edge Impulse Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an "AS
 * IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language
 * governing permissions and limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "i2c_server.h"

/*
 * The definition of get_instance method is here,
 * because I2C Server is designed as a singleton class
 * therefore unit testing of this pattern is pretty difficult.
 * To avoid such issue, for the unit test of all functionalities one
 * can exclude this file and add a custom definition which is implementing
 * non-singleton class - returns a new instance for each call of get_instance
 */

I2CServer *I2CServer::get_instance()
{
    return I2CServer::get_instance(nullptr, 0);
}

I2CServer *I2CServer::get_instance(I2CCommand_t *commands, size_t length)
{
    static I2CServer instance(commands, length);

    return &instance;
}
