#ifndef CHARACTERISTICWRITEPROCESSORE005_H
#define CHARACTERISTICWRITEPROCESSORE005_H

#include "bluetoothdevice.h"
#include "characteristicnotifier2ad9.h"
#include "characteristicwriteprocessor.h"

class CharacteristicWriteProcessorE005 : public CharacteristicWriteProcessor {
    Q_OBJECT

  public:
    explicit CharacteristicWriteProcessorE005(double bikeResistanceGain, uint8_t bikeResistanceOffset,
                                              bluetoothdevice *bike, // CharacteristicNotifier2AD9 *notifier,
                                              QObject *parent = nullptr);
    virtual int writeProcess(quint16 uuid, const QByteArray &data, QByteArray &out);

  private:
    double weight, rrc, wrc;

  signals:
    void ftmsCharacteristicChanged(const QLowEnergyCharacteristic &characteristic, const QByteArray &newValue);
};

#endif // CHARACTERISTICWRITEPROCESSORE005_H
