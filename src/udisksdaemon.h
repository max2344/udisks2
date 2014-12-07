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

#ifndef __UDISKS_DAEMON_H__
#define __UDISKS_DAEMON_H__

#include "udisksdaemontypes.h"

G_BEGIN_DECLS

#define UDISKS_TYPE_DAEMON         (udisks_daemon_get_type ())
#define UDISKS_DAEMON(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), UDISKS_TYPE_DAEMON, UDisksDaemon))
#define UDISKS_IS_DAEMON(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), UDISKS_TYPE_DAEMON))

GType                     udisks_daemon_get_type             (void) G_GNUC_CONST;
UDisksDaemon             *udisks_daemon_new                   (GDBusConnection *connection);
GDBusConnection          *udisks_daemon_get_connection        (UDisksDaemon    *daemon);
GDBusObjectManagerServer *udisks_daemon_get_object_manager    (UDisksDaemon    *daemon);
UDisksMountMonitor       *udisks_daemon_get_mount_monitor     (UDisksDaemon    *daemon);
UDisksFstabMonitor       *udisks_daemon_get_fstab_monitor     (UDisksDaemon    *daemon);
UDisksCrypttabMonitor    *udisks_daemon_get_crypttab_monitor  (UDisksDaemon    *daemon);
UDisksLinuxProvider      *udisks_daemon_get_linux_provider    (UDisksDaemon    *daemon);
PolkitAuthority          *udisks_daemon_get_authority         (UDisksDaemon    *daemon);
UDisksState              *udisks_daemon_get_state             (UDisksDaemon    *daemon);

/**
 * UDisksDaemonWaitFunc:
 * @daemon: A #UDisksDaemon.
 * @user_data: The #gpointer passed to udisks_daemon_wait_for_object_sync().
 *
 * Type for callback function used with udisks_daemon_wait_for_object_sync().
 *
 * Returns: (transfer full): %NULL if the object to wait for was not found, otherwise a full reference to a #UDisksObject.
 */
typedef UDisksObject *(*UDisksDaemonWaitFunc) (UDisksDaemon *daemon,
                                               gpointer      user_data);

UDisksObject             *udisks_daemon_wait_for_object_sync  (UDisksDaemon         *daemon,
                                                               UDisksDaemonWaitFunc  wait_func,
                                                               gpointer              user_data,
                                                               GDestroyNotify        user_data_free_func,
                                                               guint                 timeout_seconds,
                                                               GError              **error);

GList                    *udisks_daemon_get_objects           (UDisksDaemon         *daemon);

UDisksObject             *udisks_daemon_find_block            (UDisksDaemon         *daemon,
                                                               dev_t                 block_device_number);

UDisksObject             *udisks_daemon_find_block_by_device_file (UDisksDaemon *daemon,
                                                                   const gchar  *device_file);

UDisksObject             *udisks_daemon_find_block_by_sysfs_path (UDisksDaemon *daemon,
                                                                  const gchar  *sysfs_path);

UDisksObject             *udisks_daemon_find_object           (UDisksDaemon         *daemon,
                                                               const gchar          *object_path);

UDisksBaseJob            *udisks_daemon_launch_simple_job     (UDisksDaemon    *daemon,
                                                               UDisksObject    *object,
                                                               const gchar     *job_operation,
                                                               uid_t            job_started_by_uid,
                                                               GCancellable    *cancellable);
UDisksBaseJob            *udisks_daemon_launch_spawned_job    (UDisksDaemon    *daemon,
                                                               UDisksObject    *object,
                                                               const gchar     *job_operation,
                                                               uid_t            job_started_by_uid,
                                                               GCancellable    *cancellable,
                                                               uid_t            run_as_uid,
                                                               uid_t            run_as_euid,
                                                               const gchar     *input_string,
                                                               const gchar     *command_line_format,
                                                               ...) G_GNUC_PRINTF (9, 10);
gboolean                  udisks_daemon_launch_spawned_job_sync (UDisksDaemon    *daemon,
                                                                 UDisksObject    *object,
                                                                 const gchar     *job_operation,
                                                                 uid_t            job_started_by_uid,
                                                                 GCancellable    *cancellable,
                                                                 uid_t            run_as_uid,
                                                                 uid_t            run_as_euid,
                                                                 gint            *out_status,
                                                                 gchar          **out_message,
                                                                 const gchar     *input_string,
                                                                 const gchar     *command_line_format,
                                                                 ...) G_GNUC_PRINTF (11, 12);
UDisksBaseJob            *udisks_daemon_launch_threaded_job   (UDisksDaemon    *daemon,
                                                               UDisksObject    *object,
                                                               const gchar     *job_operation,
                                                               uid_t            job_started_by_uid,
                                                               UDisksThreadedJobFunc job_func,
                                                               gpointer         user_data,
                                                               GDestroyNotify   user_data_free_func,
                                                               GCancellable    *cancellable);

G_END_DECLS

#endif /* __UDISKS_DAEMON_H__ */
