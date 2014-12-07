/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2007-2010 David Zeuthen <zeuthen@gmail.com>
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

#ifndef __UDISKS_DAEMON_TYPES_H__
#define __UDISKS_DAEMON_TYPES_H__

#include <gio/gio.h>
#include <polkit/polkit.h>
#include <udisks/udisks.h>
#include <gudev/gudev.h>

#include <sys/types.h>

struct _UDisksDaemon;
typedef struct _UDisksDaemon UDisksDaemon;

struct _UDisksLinuxProvider;
typedef struct _UDisksLinuxProvider UDisksLinuxProvider;

struct _UDisksLinuxBlockObject;
typedef struct _UDisksLinuxBlockObject UDisksLinuxBlockObject;

struct _UDisksLinuxBlock;
typedef struct _UDisksLinuxBlock UDisksLinuxBlock;

struct _UDisksLinuxDriveObject;
typedef struct _UDisksLinuxDriveObject UDisksLinuxDriveObject;

struct _UDisksLinuxDrive;
typedef struct _UDisksLinuxDrive UDisksLinuxDrive;

struct _UDisksLinuxDriveAta;
typedef struct _UDisksLinuxDriveAta UDisksLinuxDriveAta;

struct _UDisksLinuxMDRaidObject;
typedef struct _UDisksLinuxMDRaidObject UDisksLinuxMDRaidObject;

struct _UDisksLinuxMDRaid;
typedef struct _UDisksLinuxMDRaid UDisksLinuxMDRaid;

struct _UDisksBaseJob;
typedef struct _UDisksBaseJob UDisksBaseJob;

struct _UDisksSpawnedJob;
typedef struct _UDisksSpawnedJob UDisksSpawnedJob;

struct _UDisksThreadedJob;
typedef struct _UDisksThreadedJob UDisksThreadedJob;

struct _UDisksSimpleJob;
typedef struct _UDisksSimpleJob UDisksSimpleJob;

struct _UDisksMountMonitor;
typedef struct _UDisksMountMonitor UDisksMountMonitor;

struct _UDisksMount;
typedef struct _UDisksMount UDisksMount;

struct _UDisksProvider;
typedef struct _UDisksProvider UDisksProvider;

struct _UDisksLinuxFilesystem;
typedef struct _UDisksLinuxFilesystem UDisksLinuxFilesystem;

struct _UDisksLinuxEncrypted;
typedef struct _UDisksLinuxEncrypted UDisksLinuxEncrypted;

struct _UDisksLinuxLoop;
typedef struct _UDisksLinuxLoop UDisksLinuxLoop;

struct _UDisksLinuxManager;
typedef struct _UDisksLinuxManager UDisksLinuxManager;

struct _UDisksLinuxSwapspace;
typedef struct _UDisksLinuxSwapspace UDisksLinuxSwapspace;

struct _UDisksFstabMonitor;
typedef struct _UDisksFstabMonitor UDisksFstabMonitor;

struct _UDisksFstabEntry;
typedef struct _UDisksFstabEntry UDisksFstabEntry;

struct _UDisksCrypttabMonitor;
typedef struct _UDisksCrypttabMonitor UDisksCrypttabMonitor;

struct _UDisksCrypttabEntry;
typedef struct _UDisksCrypttabEntry UDisksCrypttabEntry;

struct _UDisksLinuxPartition;
typedef struct _UDisksLinuxPartition UDisksLinuxPartition;

struct _UDisksLinuxPartitionTable;
typedef struct _UDisksLinuxPartitionTable UDisksLinuxPartitionTable;

struct UDisksInhibitCookie;
typedef struct UDisksInhibitCookie UDisksInhibitCookie;

/**
 * UDisksThreadedJobFunc:
 * @job: A #UDisksThreadedJob.
 * @cancellable: A #GCancellable (never %NULL).
 * @user_data: User data passed when creating @job.
 * @error: Return location for error (never %NULL).
 *
 * Job function that runs in a separate thread.
 *
 * Long-running jobs should periodically check @cancellable to see if
 * they have been cancelled.
 *
 * Returns: %TRUE if the job succeeded, %FALSE if @error is set.
 */
typedef gboolean (*UDisksThreadedJobFunc) (UDisksThreadedJob   *job,
                                           GCancellable        *cancellable,
                                           gpointer             user_data,
                                           GError             **error);

struct _UDisksState;
typedef struct _UDisksState UDisksState;

/**
 * UDisksMountType:
 * @UDISKS_MOUNT_TYPE_FILESYSTEM: Object correspond to a mounted filesystem.
 * @UDISKS_MOUNT_TYPE_SWAP: Object correspond to an in-use swap device.
 *
 * Types of a mount.
 */
typedef enum
{
  UDISKS_MOUNT_TYPE_FILESYSTEM,
  UDISKS_MOUNT_TYPE_SWAP
} UDisksMountType;


/**
 * UDisksLogLevel:
 * @UDISKS_LOG_LEVEL_DEBUG: Debug messages.
 * @UDISKS_LOG_LEVEL_INFO: Informational messages.
 * @UDISKS_LOG_LEVEL_NOTICE: Messages that the administrator should take notice of.
 * @UDISKS_LOG_LEVEL_WARNING: Warning messages.
 * @UDISKS_LOG_LEVEL_ERROR: Error messages.
 *
 * Logging levels. The level @UDISKS_LOG_LEVEL_NOTICE and above goes to syslog.
 *
 * Unlike g_warning() and g_error(), none of these logging levels causes the program to ever terminate.
 */
typedef enum
{
  UDISKS_LOG_LEVEL_DEBUG,
  UDISKS_LOG_LEVEL_INFO,
  UDISKS_LOG_LEVEL_NOTICE,
  UDISKS_LOG_LEVEL_WARNING,
  UDISKS_LOG_LEVEL_ERROR
} UDisksLogLevel;

struct _UDisksAtaCommandOutput;
typedef struct _UDisksAtaCommandOutput UDisksAtaCommandOutput;

struct _UDisksAtaCommandInput;
typedef struct _UDisksAtaCommandInput UDisksAtaCommandInput;

/**
 * UDisksAtaCommandProtocol:
 * @UDISKS_ATA_COMMAND_PROTOCOL_NONE: Non-data
 * @UDISKS_ATA_COMMAND_PROTOCOL_DRIVE_TO_HOST: PIO Data-In
 * @UDISKS_ATA_COMMAND_PROTOCOL_HOST_TO_DRIVE: PIO Data-Out
 *
 * Enumeration used to specify the protocol of an ATA command
 */
typedef enum
{
  UDISKS_ATA_COMMAND_PROTOCOL_NONE,
  UDISKS_ATA_COMMAND_PROTOCOL_DRIVE_TO_HOST,
  UDISKS_ATA_COMMAND_PROTOCOL_HOST_TO_DRIVE
} UDisksAtaCommandProtocol;

struct _UDisksLinuxDevice;
typedef struct _UDisksLinuxDevice UDisksLinuxDevice;

#endif /* __UDISKS_DAEMON_TYPES_H__ */
