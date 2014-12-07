/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2008-2010 David Zeuthen <zeuthen@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef __UDISKS_LINUX_DEVICE_H__
#define __UDISKS_LINUX_DEVICE_H__

#include "udisksdaemontypes.h"

G_BEGIN_DECLS

#define UDISKS_TYPE_LINUX_DEVICE  (udisks_linux_device_get_type ())
#define UDISKS_LINUX_DEVICE(o)    (G_TYPE_CHECK_INSTANCE_CAST ((o), UDISKS_TYPE_LINUX_DEVICE, UDisksLinuxDevice))
#define UDISKS_IS_LINUX_DEVICE(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), UDISKS_TYPE_LINUX_DEVICE))

/**
 * UDisksLinuxDevice:
 * @udev_device: A #GUdevDevice.
 * @ata_identify_device_data: 512-byte array containing the result of the IDENTIY DEVICE command or %NULL.
 * @ata_identify_packet_device_data: 512-byte array containing the result of the IDENTIY PACKET DEVICE command or %NULL.
 *
 * Object containing information about a device on Linux. This is
 * essentially an instance of #GUdevDevice plus additional data - such
 * as ATA IDENTIFY data - obtained via probing the device at discovery
 * and uevent "change" time.
 */
struct _UDisksLinuxDevice
{
  /*< private >*/
  GObject parent_instance;
  /*< public >*/
  GUdevDevice *udev_device;
  guchar *ata_identify_device_data;
  guchar *ata_identify_packet_device_data;
};

GType              udisks_linux_device_get_type     (void) G_GNUC_CONST;
UDisksLinuxDevice *udisks_linux_device_new_sync     (GUdevDevice *udev_device);
gboolean           udisks_linux_device_reprobe_sync (UDisksLinuxDevice  *device,
                                                     GCancellable       *cancellable,
                                                     GError            **error);

G_END_DECLS

#endif /* __UDISKS_LINUX_DEVICE_H__ */
