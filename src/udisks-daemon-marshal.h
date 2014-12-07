
#ifndef __udisks_daemon_marshal_MARSHAL_H__
#define __udisks_daemon_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* BOOLEAN:BOXED,INT,BOXED,BOXED (udisks-daemon-marshal.list:1) */
extern void udisks_daemon_marshal_BOOLEAN__BOXED_INT_BOXED_BOXED (GClosure     *closure,
                                                                  GValue       *return_value,
                                                                  guint         n_param_values,
                                                                  const GValue *param_values,
                                                                  gpointer      invocation_hint,
                                                                  gpointer      marshal_data);

/* BOOLEAN:BOOLEAN,BOXED (udisks-daemon-marshal.list:2) */
extern void udisks_daemon_marshal_BOOLEAN__BOOLEAN_BOXED (GClosure     *closure,
                                                          GValue       *return_value,
                                                          guint         n_param_values,
                                                          const GValue *param_values,
                                                          gpointer      invocation_hint,
                                                          gpointer      marshal_data);

G_END_DECLS

#endif /* __udisks_daemon_marshal_MARSHAL_H__ */

