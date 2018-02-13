/*  =========================================================================
    zyre Node.js binding implementation

    Copyright (c) the Contributors as noted in the AUTHORS file.

    This file is part of Zyre, an open-source framework for proximity-based
    peer-to-peer applications -- See http://zyre.org.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
    =========================================================================
*/

#include "binding.h"

using namespace v8;
using namespace Nan;

NAN_MODULE_INIT (Zyre::Init) {
    Nan::HandleScope scope;

    // Prepare constructor template
    Local <FunctionTemplate> tpl = Nan::New <FunctionTemplate> (New);
    tpl->SetClassName (Nan::New ("Zyre").ToLocalChecked ());
    tpl->InstanceTemplate ()->SetInternalFieldCount (1);

    // Prototypes
    Nan::SetPrototypeMethod (tpl, "destroy", destroy);
    Nan::SetPrototypeMethod (tpl, "defined", defined);
    Nan::SetPrototypeMethod (tpl, "uuid", _uuid);
    Nan::SetPrototypeMethod (tpl, "name", _name);
    Nan::SetPrototypeMethod (tpl, "setName", _set_name);
    Nan::SetPrototypeMethod (tpl, "setHeader", _set_header);
    Nan::SetPrototypeMethod (tpl, "setVerbose", _set_verbose);
    Nan::SetPrototypeMethod (tpl, "setPort", _set_port);
    Nan::SetPrototypeMethod (tpl, "setEvasiveTimeout", _set_evasive_timeout);
    Nan::SetPrototypeMethod (tpl, "setExpiredTimeout", _set_expired_timeout);
    Nan::SetPrototypeMethod (tpl, "setInterval", _set_interval);
    Nan::SetPrototypeMethod (tpl, "setInterface", _set_interface);
    Nan::SetPrototypeMethod (tpl, "setEndpoint", _set_endpoint);
    Nan::SetPrototypeMethod (tpl, "setAdvertisedEndpoint", _set_advertised_endpoint);
    Nan::SetPrototypeMethod (tpl, "setZcert", _set_zcert);
    Nan::SetPrototypeMethod (tpl, "setZapDomain", _set_zap_domain);
    Nan::SetPrototypeMethod (tpl, "gossipBind", _gossip_bind);
    Nan::SetPrototypeMethod (tpl, "gossipConnect", _gossip_connect);
    Nan::SetPrototypeMethod (tpl, "gossipConnectCurve", _gossip_connect_curve);
    Nan::SetPrototypeMethod (tpl, "start", _start);
    Nan::SetPrototypeMethod (tpl, "stop", _stop);
    Nan::SetPrototypeMethod (tpl, "join", _join);
    Nan::SetPrototypeMethod (tpl, "leave", _leave);
    Nan::SetPrototypeMethod (tpl, "recv", _recv);
    Nan::SetPrototypeMethod (tpl, "whisper", _whisper);
    Nan::SetPrototypeMethod (tpl, "shout", _shout);
    Nan::SetPrototypeMethod (tpl, "whispers", _whispers);
    Nan::SetPrototypeMethod (tpl, "shouts", _shouts);
    Nan::SetPrototypeMethod (tpl, "peers", _peers);
    Nan::SetPrototypeMethod (tpl, "peersByGroup", _peers_by_group);
    Nan::SetPrototypeMethod (tpl, "ownGroups", _own_groups);
    Nan::SetPrototypeMethod (tpl, "peerGroups", _peer_groups);
    Nan::SetPrototypeMethod (tpl, "peerAddress", _peer_address);
    Nan::SetPrototypeMethod (tpl, "peerHeaderValue", _peer_header_value);
    Nan::SetPrototypeMethod (tpl, "requirePeer", _require_peer);
    Nan::SetPrototypeMethod (tpl, "socket", _socket);
    Nan::SetPrototypeMethod (tpl, "print", _print);
    Nan::SetPrototypeMethod (tpl, "version", _version);
    Nan::SetPrototypeMethod (tpl, "test", _test);

    constructor ().Reset (Nan::GetFunction (tpl).ToLocalChecked ());
    Nan::Set (target, Nan::New ("Zyre").ToLocalChecked (),
    Nan::GetFunction (tpl).ToLocalChecked ());
}

Zyre::Zyre (const char *name) {
    self = zyre_new ((const char *)name);
}

Zyre::Zyre (zyre_t *self_) {
    self = self_;
}

Zyre::~Zyre () {
}

NAN_METHOD (Zyre::New) {
    assert (info.IsConstructCall ());
    char *name;
    if (info [0]->IsUndefined ())
        name = NULL;
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`name` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String name_utf8 (info [0].As<String>());
    name = *name_utf8;
         //} //bjornw end
    Zyre *zyre = new Zyre ((const char *)name);
    if (zyre) {
        zyre->Wrap (info.This ());
        info.GetReturnValue ().Set (info.This ());
    }
}

NAN_METHOD (Zyre::destroy) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    zyre_destroy (&zyre->self);
}


NAN_METHOD (Zyre::defined) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    info.GetReturnValue ().Set (Nan::New (zyre->self != NULL));
}

NAN_METHOD (Zyre::_uuid) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *result = (char *) zyre_uuid (zyre->self);
    info.GetReturnValue ().Set (Nan::New (result).ToLocalChecked ());
}

NAN_METHOD (Zyre::_name) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *result = (char *) zyre_name (zyre->self);
    info.GetReturnValue ().Set (Nan::New (result).ToLocalChecked ());
}

NAN_METHOD (Zyre::_set_name) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *name;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `name`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`name` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String name_utf8 (info [0].As<String>());
    name = *name_utf8;
         //} //bjornw end
    zyre_set_name (zyre->self, (const char *)name);
}

NAN_METHOD (Zyre::_set_header) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *name;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `name`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`name` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String name_utf8 (info [0].As<String>());
    name = *name_utf8;
         //} //bjornw end
    char *format;
    if (info [1]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `format`");
    else
    if (!info [1]->IsString ())
        return Nan::ThrowTypeError ("`format` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String format_utf8 (info [1].As<String>());
    format = *format_utf8;
         //} //bjornw end
    zyre_set_header (zyre->self, (const char *)name, "%s", format);
}

NAN_METHOD (Zyre::_set_verbose) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    zyre_set_verbose (zyre->self);
}

NAN_METHOD (Zyre::_set_port) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `port nbr`");

    //int port_nbr; // bjornw typedef - if using c_type, then you get 'int * major' but it needs to be 'int major'. later using the FromJust() returns an int
    int port_nbr;


    if (info [0]->IsNumber ())
    {
          port_nbr = Nan::To<int>(info [0]).FromJust ();
    }
    else
        return Nan::ThrowTypeError ("`port nbr` must be a number");
    zyre_set_port (zyre->self, (int) port_nbr);
}

NAN_METHOD (Zyre::_set_evasive_timeout) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `interval`");

    //int interval; // bjornw typedef - if using c_type, then you get 'int * major' but it needs to be 'int major'. later using the FromJust() returns an int
    int interval;


    if (info [0]->IsNumber ())
    {
          interval = Nan::To<int>(info [0]).FromJust ();
    }
    else
        return Nan::ThrowTypeError ("`interval` must be a number");
    zyre_set_evasive_timeout (zyre->self, (int) interval);
}

NAN_METHOD (Zyre::_set_expired_timeout) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `interval`");

    //int interval; // bjornw typedef - if using c_type, then you get 'int * major' but it needs to be 'int major'. later using the FromJust() returns an int
    int interval;


    if (info [0]->IsNumber ())
    {
          interval = Nan::To<int>(info [0]).FromJust ();
    }
    else
        return Nan::ThrowTypeError ("`interval` must be a number");
    zyre_set_expired_timeout (zyre->self, (int) interval);
}

NAN_METHOD (Zyre::_set_interval) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `interval`");
    else
    if (!info [0]->IsNumber ())
        return Nan::ThrowTypeError ("`interval` must be a number");
    size_t interval = Nan::To<int64_t>(info [0]).FromJust ();
    zyre_set_interval (zyre->self, (size_t) interval);
}

NAN_METHOD (Zyre::_set_interface) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *value;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `value`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`value` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String value_utf8 (info [0].As<String>());
    value = *value_utf8;
         //} //bjornw end
    zyre_set_interface (zyre->self, (const char *)value);
}

NAN_METHOD (Zyre::_set_endpoint) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *format;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `format`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`format` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String format_utf8 (info [0].As<String>());
    format = *format_utf8;
         //} //bjornw end
    int result = zyre_set_endpoint (zyre->self, "%s", format);
    info.GetReturnValue ().Set (Nan::New<Number>(result));
}

NAN_METHOD (Zyre::_set_advertised_endpoint) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *value;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `value`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`value` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String value_utf8 (info [0].As<String>());
    value = *value_utf8;
         //} //bjornw end
    zyre_set_advertised_endpoint (zyre->self, (const char *)value);
}

NAN_METHOD (Zyre::_set_zcert) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    Zcert *zcert = Nan::ObjectWrap::Unwrap<Zcert>(info [0].As<Object>());
    zyre_set_zcert (zyre->self, zcert->self);
}

NAN_METHOD (Zyre::_set_zap_domain) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *domain;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `domain`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`domain` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String domain_utf8 (info [0].As<String>());
    domain = *domain_utf8;
         //} //bjornw end
    zyre_set_zap_domain (zyre->self, (const char *)domain);
}

NAN_METHOD (Zyre::_gossip_bind) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *format;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `format`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`format` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String format_utf8 (info [0].As<String>());
    format = *format_utf8;
         //} //bjornw end
    zyre_gossip_bind (zyre->self, "%s", format);
}

NAN_METHOD (Zyre::_gossip_connect) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *format;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `format`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`format` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String format_utf8 (info [0].As<String>());
    format = *format_utf8;
         //} //bjornw end
    zyre_gossip_connect (zyre->self, "%s", format);
}

NAN_METHOD (Zyre::_gossip_connect_curve) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *public_key;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `public_key`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`public_key` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String public_key_utf8 (info [0].As<String>());
    public_key = *public_key_utf8;
         //} //bjornw end
    char *format;
    if (info [1]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `format`");
    else
    if (!info [1]->IsString ())
        return Nan::ThrowTypeError ("`format` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String format_utf8 (info [1].As<String>());
    format = *format_utf8;
         //} //bjornw end
    zyre_gossip_connect_curve (zyre->self, (const char *)public_key, "%s", format);
}

NAN_METHOD (Zyre::_start) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    int result = zyre_start (zyre->self);
    info.GetReturnValue ().Set (Nan::New<Number>(result));
}

NAN_METHOD (Zyre::_stop) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    zyre_stop (zyre->self);
}

NAN_METHOD (Zyre::_join) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *group;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `group`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`group` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String group_utf8 (info [0].As<String>());
    group = *group_utf8;
         //} //bjornw end
    int result = zyre_join (zyre->self, (const char *)group);
    info.GetReturnValue ().Set (Nan::New<Number>(result));
}

NAN_METHOD (Zyre::_leave) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *group;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `group`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`group` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String group_utf8 (info [0].As<String>());
    group = *group_utf8;
         //} //bjornw end
    int result = zyre_leave (zyre->self, (const char *)group);
    info.GetReturnValue ().Set (Nan::New<Number>(result));
}

NAN_METHOD (Zyre::_recv) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    zmsg_t *result = zyre_recv (zyre->self);
    Zmsg *zmsg_result = new Zmsg (result);
    if (zmsg_result) {
    //  Don't yet know how to return a new object
    //      zmsg->Wrap (info.This ());
    //      info.GetReturnValue ().Set (info.This ());
        info.GetReturnValue ().Set (Nan::New<Boolean>(true));
    }
}

NAN_METHOD (Zyre::_whisper) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *peer;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `peer`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`peer` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String peer_utf8 (info [0].As<String>());
    peer = *peer_utf8;
         //} //bjornw end
    Zmsg *msg_p = Nan::ObjectWrap::Unwrap<Zmsg>(info [1].As<Object>());
    int result = zyre_whisper (zyre->self, (const char *)peer, &msg_p->self);
    info.GetReturnValue ().Set (Nan::New<Number>(result));
}

NAN_METHOD (Zyre::_shout) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *group;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `group`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`group` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String group_utf8 (info [0].As<String>());
    group = *group_utf8;
         //} //bjornw end
    Zmsg *msg_p = Nan::ObjectWrap::Unwrap<Zmsg>(info [1].As<Object>());
    int result = zyre_shout (zyre->self, (const char *)group, &msg_p->self);
    info.GetReturnValue ().Set (Nan::New<Number>(result));
}

NAN_METHOD (Zyre::_whispers) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *peer;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `peer`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`peer` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String peer_utf8 (info [0].As<String>());
    peer = *peer_utf8;
         //} //bjornw end
    char *format;
    if (info [1]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `format`");
    else
    if (!info [1]->IsString ())
        return Nan::ThrowTypeError ("`format` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String format_utf8 (info [1].As<String>());
    format = *format_utf8;
         //} //bjornw end
    int result = zyre_whispers (zyre->self, (const char *)peer, "%s", format);
    info.GetReturnValue ().Set (Nan::New<Number>(result));
}

NAN_METHOD (Zyre::_shouts) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *group;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `group`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`group` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String group_utf8 (info [0].As<String>());
    group = *group_utf8;
         //} //bjornw end
    char *format;
    if (info [1]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `format`");
    else
    if (!info [1]->IsString ())
        return Nan::ThrowTypeError ("`format` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String format_utf8 (info [1].As<String>());
    format = *format_utf8;
         //} //bjornw end
    int result = zyre_shouts (zyre->self, (const char *)group, "%s", format);
    info.GetReturnValue ().Set (Nan::New<Number>(result));
}

NAN_METHOD (Zyre::_peers) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    zlist_t *result = zyre_peers (zyre->self);
    Zlist *zlist_result = new Zlist (result);
    if (zlist_result) {
    //  Don't yet know how to return a new object
    //      zlist->Wrap (info.This ());
    //      info.GetReturnValue ().Set (info.This ());
        info.GetReturnValue ().Set (Nan::New<Boolean>(true));
    }
}

NAN_METHOD (Zyre::_peers_by_group) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *name;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `name`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`name` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String name_utf8 (info [0].As<String>());
    name = *name_utf8;
         //} //bjornw end
    zlist_t *result = zyre_peers_by_group (zyre->self, (const char *)name);
    Zlist *zlist_result = new Zlist (result);
    if (zlist_result) {
    //  Don't yet know how to return a new object
    //      zlist->Wrap (info.This ());
    //      info.GetReturnValue ().Set (info.This ());
        info.GetReturnValue ().Set (Nan::New<Boolean>(true));
    }
}

NAN_METHOD (Zyre::_own_groups) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    zlist_t *result = zyre_own_groups (zyre->self);
    Zlist *zlist_result = new Zlist (result);
    if (zlist_result) {
    //  Don't yet know how to return a new object
    //      zlist->Wrap (info.This ());
    //      info.GetReturnValue ().Set (info.This ());
        info.GetReturnValue ().Set (Nan::New<Boolean>(true));
    }
}

NAN_METHOD (Zyre::_peer_groups) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    zlist_t *result = zyre_peer_groups (zyre->self);
    Zlist *zlist_result = new Zlist (result);
    if (zlist_result) {
    //  Don't yet know how to return a new object
    //      zlist->Wrap (info.This ());
    //      info.GetReturnValue ().Set (info.This ());
        info.GetReturnValue ().Set (Nan::New<Boolean>(true));
    }
}

NAN_METHOD (Zyre::_peer_address) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *peer;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `peer`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`peer` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String peer_utf8 (info [0].As<String>());
    peer = *peer_utf8;
         //} //bjornw end
    char *result = (char *) zyre_peer_address (zyre->self, (const char *)peer);
    info.GetReturnValue ().Set (Nan::New (result).ToLocalChecked ());
}

NAN_METHOD (Zyre::_peer_header_value) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *peer;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `peer`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`peer` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String peer_utf8 (info [0].As<String>());
    peer = *peer_utf8;
         //} //bjornw end
    char *name;
    if (info [1]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `name`");
    else
    if (!info [1]->IsString ())
        return Nan::ThrowTypeError ("`name` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String name_utf8 (info [1].As<String>());
    name = *name_utf8;
         //} //bjornw end
    char *result = (char *) zyre_peer_header_value (zyre->self, (const char *)peer, (const char *)name);
    info.GetReturnValue ().Set (Nan::New (result).ToLocalChecked ());
}

NAN_METHOD (Zyre::_require_peer) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    char *uuid;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `uuid`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`uuid` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String uuid_utf8 (info [0].As<String>());
    uuid = *uuid_utf8;
         //} //bjornw end
    char *endpoint;
    if (info [1]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `endpoint`");
    else
    if (!info [1]->IsString ())
        return Nan::ThrowTypeError ("`endpoint` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String endpoint_utf8 (info [1].As<String>());
    endpoint = *endpoint_utf8;
         //} //bjornw end
    char *public_key;
    if (info [2]->IsUndefined ())
        public_key = NULL;
    else
    if (!info [2]->IsString ())
        return Nan::ThrowTypeError ("`public_key` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String public_key_utf8 (info [2].As<String>());
    public_key = *public_key_utf8;
         //} //bjornw end
    int result = zyre_require_peer (zyre->self, (const char *)uuid, (const char *)endpoint, (const char *)public_key);
    info.GetReturnValue ().Set (Nan::New<Number>(result));
}

NAN_METHOD (Zyre::_socket) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    zsock_t *result = zyre_socket (zyre->self);
    Zsock *zsock_result = new Zsock (result);
    if (zsock_result) {
    //  Don't yet know how to return a new object
    //      zsock->Wrap (info.This ());
    //      info.GetReturnValue ().Set (info.This ());
        info.GetReturnValue ().Set (Nan::New<Boolean>(true));
    }
}

NAN_METHOD (Zyre::_print) {
    Zyre *zyre = Nan::ObjectWrap::Unwrap <Zyre> (info.Holder ());
    zyre_print (zyre->self);
}

NAN_METHOD (Zyre::_version) {
    uint64_t result = zyre_version ();
    info.GetReturnValue ().Set (Nan::New<Number>(result));
}

NAN_METHOD (Zyre::_test) {
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `verbose`");

    //bool verbose; // bjornw typedef - if using c_type, then you get 'int * major' but it needs to be 'int major'. later using the FromJust() returns an int
    bool verbose;


    if (info [0]->IsBoolean ())
    {
          verbose = Nan::To<bool>(info [0]).FromJust ();
    }
    else
        return Nan::ThrowTypeError ("`verbose` must be a Boolean");
    zyre_test ((bool) verbose);
}

Nan::Persistent <Function> &Zyre::constructor () {
    static Nan::Persistent <Function> my_constructor;
    return my_constructor;
}


NAN_MODULE_INIT (ZyreEvent::Init) {
    Nan::HandleScope scope;

    // Prepare constructor template
    Local <FunctionTemplate> tpl = Nan::New <FunctionTemplate> (New);
    tpl->SetClassName (Nan::New ("ZyreEvent").ToLocalChecked ());
    tpl->InstanceTemplate ()->SetInternalFieldCount (1);

    // Prototypes
    Nan::SetPrototypeMethod (tpl, "destroy", destroy);
    Nan::SetPrototypeMethod (tpl, "defined", defined);
    Nan::SetPrototypeMethod (tpl, "type", _type);
    Nan::SetPrototypeMethod (tpl, "peerUuid", _peer_uuid);
    Nan::SetPrototypeMethod (tpl, "peerName", _peer_name);
    Nan::SetPrototypeMethod (tpl, "peerAddr", _peer_addr);
    Nan::SetPrototypeMethod (tpl, "headers", _headers);
    Nan::SetPrototypeMethod (tpl, "header", _header);
    Nan::SetPrototypeMethod (tpl, "group", _group);
    Nan::SetPrototypeMethod (tpl, "msg", _msg);
    Nan::SetPrototypeMethod (tpl, "getMsg", _get_msg);
    Nan::SetPrototypeMethod (tpl, "print", _print);
    Nan::SetPrototypeMethod (tpl, "test", _test);

    constructor ().Reset (Nan::GetFunction (tpl).ToLocalChecked ());
    Nan::Set (target, Nan::New ("ZyreEvent").ToLocalChecked (),
    Nan::GetFunction (tpl).ToLocalChecked ());
}

ZyreEvent::ZyreEvent (zyre_t *node) {
    self = zyre_event_new (node);
}

ZyreEvent::ZyreEvent (zyre_event_t *self_) {
    self = self_;
}

ZyreEvent::~ZyreEvent () {
}

NAN_METHOD (ZyreEvent::New) {
    assert (info.IsConstructCall ());
    Zyre *node = Nan::ObjectWrap::Unwrap<Zyre>(info [0].As<Object>());
    ZyreEvent *zyre_event = new ZyreEvent (node->self);
    if (zyre_event) {
        zyre_event->Wrap (info.This ());
        info.GetReturnValue ().Set (info.This ());
    }
}

NAN_METHOD (ZyreEvent::destroy) {
    ZyreEvent *zyre_event = Nan::ObjectWrap::Unwrap <ZyreEvent> (info.Holder ());
    zyre_event_destroy (&zyre_event->self);
}


NAN_METHOD (ZyreEvent::defined) {
    ZyreEvent *zyre_event = Nan::ObjectWrap::Unwrap <ZyreEvent> (info.Holder ());
    info.GetReturnValue ().Set (Nan::New (zyre_event->self != NULL));
}

NAN_METHOD (ZyreEvent::_type) {
    ZyreEvent *zyre_event = Nan::ObjectWrap::Unwrap <ZyreEvent> (info.Holder ());
    char *result = (char *) zyre_event_type (zyre_event->self);
    info.GetReturnValue ().Set (Nan::New (result).ToLocalChecked ());
}

NAN_METHOD (ZyreEvent::_peer_uuid) {
    ZyreEvent *zyre_event = Nan::ObjectWrap::Unwrap <ZyreEvent> (info.Holder ());
    char *result = (char *) zyre_event_peer_uuid (zyre_event->self);
    info.GetReturnValue ().Set (Nan::New (result).ToLocalChecked ());
}

NAN_METHOD (ZyreEvent::_peer_name) {
    ZyreEvent *zyre_event = Nan::ObjectWrap::Unwrap <ZyreEvent> (info.Holder ());
    char *result = (char *) zyre_event_peer_name (zyre_event->self);
    info.GetReturnValue ().Set (Nan::New (result).ToLocalChecked ());
}

NAN_METHOD (ZyreEvent::_peer_addr) {
    ZyreEvent *zyre_event = Nan::ObjectWrap::Unwrap <ZyreEvent> (info.Holder ());
    char *result = (char *) zyre_event_peer_addr (zyre_event->self);
    info.GetReturnValue ().Set (Nan::New (result).ToLocalChecked ());
}

NAN_METHOD (ZyreEvent::_headers) {
    ZyreEvent *zyre_event = Nan::ObjectWrap::Unwrap <ZyreEvent> (info.Holder ());
    zhash_t *result = zyre_event_headers (zyre_event->self);
    Zhash *zhash_result = new Zhash (result);
    if (zhash_result) {
    //  Don't yet know how to return a new object
    //      zhash->Wrap (info.This ());
    //      info.GetReturnValue ().Set (info.This ());
        info.GetReturnValue ().Set (Nan::New<Boolean>(true));
    }
}

NAN_METHOD (ZyreEvent::_header) {
    ZyreEvent *zyre_event = Nan::ObjectWrap::Unwrap <ZyreEvent> (info.Holder ());
    char *name;
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `name`");
    else
    if (!info [0]->IsString ())
        return Nan::ThrowTypeError ("`name` must be a string");
    //else { // bjornw: remove brackets to keep scope
    Nan::Utf8String name_utf8 (info [0].As<String>());
    name = *name_utf8;
         //} //bjornw end
    char *result = (char *) zyre_event_header (zyre_event->self, (const char *)name);
    info.GetReturnValue ().Set (Nan::New (result).ToLocalChecked ());
}

NAN_METHOD (ZyreEvent::_group) {
    ZyreEvent *zyre_event = Nan::ObjectWrap::Unwrap <ZyreEvent> (info.Holder ());
    char *result = (char *) zyre_event_group (zyre_event->self);
    info.GetReturnValue ().Set (Nan::New (result).ToLocalChecked ());
}

NAN_METHOD (ZyreEvent::_msg) {
    ZyreEvent *zyre_event = Nan::ObjectWrap::Unwrap <ZyreEvent> (info.Holder ());
    zmsg_t *result = zyre_event_msg (zyre_event->self);
    Zmsg *zmsg_result = new Zmsg (result);
    if (zmsg_result) {
    //  Don't yet know how to return a new object
    //      zmsg->Wrap (info.This ());
    //      info.GetReturnValue ().Set (info.This ());
        info.GetReturnValue ().Set (Nan::New<Boolean>(true));
    }
}

NAN_METHOD (ZyreEvent::_get_msg) {
    ZyreEvent *zyre_event = Nan::ObjectWrap::Unwrap <ZyreEvent> (info.Holder ());
    zmsg_t *result = zyre_event_get_msg (zyre_event->self);
    Zmsg *zmsg_result = new Zmsg (result);
    if (zmsg_result) {
    //  Don't yet know how to return a new object
    //      zmsg->Wrap (info.This ());
    //      info.GetReturnValue ().Set (info.This ());
        info.GetReturnValue ().Set (Nan::New<Boolean>(true));
    }
}

NAN_METHOD (ZyreEvent::_print) {
    ZyreEvent *zyre_event = Nan::ObjectWrap::Unwrap <ZyreEvent> (info.Holder ());
    zyre_event_print (zyre_event->self);
}

NAN_METHOD (ZyreEvent::_test) {
    if (info [0]->IsUndefined ())
        return Nan::ThrowTypeError ("method requires a `verbose`");

    //bool verbose; // bjornw typedef - if using c_type, then you get 'int * major' but it needs to be 'int major'. later using the FromJust() returns an int
    bool verbose;


    if (info [0]->IsBoolean ())
    {
          verbose = Nan::To<bool>(info [0]).FromJust ();
    }
    else
        return Nan::ThrowTypeError ("`verbose` must be a Boolean");
    zyre_event_test ((bool) verbose);
}

Nan::Persistent <Function> &ZyreEvent::constructor () {
    static Nan::Persistent <Function> my_constructor;
    return my_constructor;
}


extern "C" NAN_MODULE_INIT (zyre_initialize)
{
    Zyre::Init (target);
    ZyreEvent::Init (target);
}

NODE_MODULE (zyre, zyre_initialize)
