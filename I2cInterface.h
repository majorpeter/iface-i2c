/*
 * I2cInterface.h
 *
 *  Created on: 2018. máj. 16.
 *      Author: peti
 */

#ifndef MODULES_IFACE_I2C_I2CINTERFACE_H_
#define MODULES_IFACE_I2C_I2CINTERFACE_H_

#include <stdint.h>

class I2cInterface {
public:
    /**
     * write bytes to slave device
     * @param slave_address 8-bit slave address, contains the R/nW=0 bit
     * @param data bytes to write
     * @param length number of bytes to write
     * @return 0 on success
     */
    virtual int8_t write(uint8_t slave_address, const uint8_t* data, uint16_t length) = 0;

    /**
     * read bytes from slave device
     * @param slave_address 8-bit slave address, contains the R/nW=1 bit
     * @param buffer to read to
     * @param length number of bytes to read
     * @return 0 on success
     */
    virtual int8_t read(uint8_t slave_address, uint8_t* data, uint16_t length) = 0;

    /**
     * generate 9 Stop conditions that reset all I2C slave's that may be in an erroneous condition
     * @note this is particularly useful when a slave does not have a discrete reset pin and the
     *       host is restarted while communicating with it
     * @return 0 on success
     */
    virtual int8_t resetBus() = 0;

    virtual ~I2cInterface() {}
};

#endif /* MODULES_IFACE_I2C_I2CINTERFACE_H_ */
