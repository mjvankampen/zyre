################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################

from __future__ import print_function
import os, sys
from ctypes import *
from ctypes.util import find_library
import czmq

# load libc to access free, etc.
libcpath = find_library("c")
if not libcpath:
    raise ImportError("Unable to find libc")
libc = cdll.LoadLibrary(libcpath)
libc.free.argtypes = [c_void_p]
libc.free.restype = None

def return_fresh_string(char_p):
    s = string_at(char_p)
    libc.free(char_p)
    return s

# zyre
lib = None
# check to see if the shared object was embedded locally, attempt to load it
# if not, try to load it using the default system paths...
# we need to use os.chdir instead of trying to modify $LD_LIBRARY_PATH and reloading the interpreter
t = os.getcwd()
p = os.path.join(os.path.dirname(__file__), '..')  # find the path to our $project_ctypes.py
os.chdir(p)  # change directories briefly

try:
    from zyre import libzyre                        # attempt to import the shared lib if it exists
    lib = CDLL(libzyre.__file__)             # if it exists try to load the shared lib
except ImportError:
    pass
finally:
    os.chdir(t)  # switch back to orig dir

if not lib:
    try:
        # If LD_LIBRARY_PATH or your OSs equivalent is set, this is the only way to
        # load the library.  If we use find_library below, we get the wrong result.
        if os.name == 'posix':
            if sys.platform == 'darwin':
                lib = cdll.LoadLibrary('libzyre.2.dylib')
            else:
                lib = cdll.LoadLibrary("libzyre.so.2")
        elif os.name == 'nt':
            lib = cdll.LoadLibrary('libzyre.dll')
    except OSError:
        libpath = find_library("zyre")
        if not libpath:
            raise ImportError("Unable to find libzyre")
        lib = cdll.LoadLibrary(libpath)

class zyre_t(Structure):
    pass # Empty - only for type checking
zyre_p = POINTER(zyre_t)

class zyre_event_t(Structure):
    pass # Empty - only for type checking
zyre_event_p = POINTER(zyre_event_t)


# zyre
lib.zyre_new.restype = zyre_p
lib.zyre_new.argtypes = [c_char_p]
lib.zyre_destroy.restype = None
lib.zyre_destroy.argtypes = [POINTER(zyre_p)]
lib.zyre_uuid.restype = c_char_p
lib.zyre_uuid.argtypes = [zyre_p]
lib.zyre_name.restype = c_char_p
lib.zyre_name.argtypes = [zyre_p]
lib.zyre_set_name.restype = None
lib.zyre_set_name.argtypes = [zyre_p, c_char_p]
lib.zyre_set_header.restype = None
lib.zyre_set_header.argtypes = [zyre_p, c_char_p, c_char_p]
lib.zyre_set_verbose.restype = None
lib.zyre_set_verbose.argtypes = [zyre_p]
lib.zyre_set_port.restype = None
lib.zyre_set_port.argtypes = [zyre_p, c_int]
lib.zyre_set_evasive_timeout.restype = None
lib.zyre_set_evasive_timeout.argtypes = [zyre_p, c_int]
lib.zyre_set_expired_timeout.restype = None
lib.zyre_set_expired_timeout.argtypes = [zyre_p, c_int]
lib.zyre_set_interval.restype = None
lib.zyre_set_interval.argtypes = [zyre_p, c_size_t]
lib.zyre_set_interface.restype = None
lib.zyre_set_interface.argtypes = [zyre_p, c_char_p]
lib.zyre_set_endpoint.restype = c_int
lib.zyre_set_endpoint.argtypes = [zyre_p, c_char_p]
lib.zyre_set_advertised_endpoint.restype = None
lib.zyre_set_advertised_endpoint.argtypes = [zyre_p, c_char_p]
lib.zyre_set_zcert.restype = None
lib.zyre_set_zcert.argtypes = [zyre_p, czmq.zcert_p]
lib.zyre_set_zap_domain.restype = None
lib.zyre_set_zap_domain.argtypes = [zyre_p, c_char_p]
lib.zyre_gossip_bind.restype = None
lib.zyre_gossip_bind.argtypes = [zyre_p, c_char_p]
lib.zyre_gossip_connect.restype = None
lib.zyre_gossip_connect.argtypes = [zyre_p, c_char_p]
lib.zyre_gossip_connect_curve.restype = None
lib.zyre_gossip_connect_curve.argtypes = [zyre_p, c_char_p, c_char_p]
lib.zyre_start.restype = c_int
lib.zyre_start.argtypes = [zyre_p]
lib.zyre_stop.restype = None
lib.zyre_stop.argtypes = [zyre_p]
lib.zyre_join.restype = c_int
lib.zyre_join.argtypes = [zyre_p, c_char_p]
lib.zyre_leave.restype = c_int
lib.zyre_leave.argtypes = [zyre_p, c_char_p]
lib.zyre_recv.restype = czmq.zmsg_p
lib.zyre_recv.argtypes = [zyre_p]
lib.zyre_whisper.restype = c_int
lib.zyre_whisper.argtypes = [zyre_p, c_char_p, POINTER(czmq.zmsg_p)]
lib.zyre_shout.restype = c_int
lib.zyre_shout.argtypes = [zyre_p, c_char_p, POINTER(czmq.zmsg_p)]
lib.zyre_whispers.restype = c_int
lib.zyre_whispers.argtypes = [zyre_p, c_char_p, c_char_p]
lib.zyre_shouts.restype = c_int
lib.zyre_shouts.argtypes = [zyre_p, c_char_p, c_char_p]
lib.zyre_peers.restype = czmq.zlist_p
lib.zyre_peers.argtypes = [zyre_p]
lib.zyre_peers_by_group.restype = czmq.zlist_p
lib.zyre_peers_by_group.argtypes = [zyre_p, c_char_p]
lib.zyre_own_groups.restype = czmq.zlist_p
lib.zyre_own_groups.argtypes = [zyre_p]
lib.zyre_peer_groups.restype = czmq.zlist_p
lib.zyre_peer_groups.argtypes = [zyre_p]
lib.zyre_peer_address.restype = POINTER(c_char)
lib.zyre_peer_address.argtypes = [zyre_p, c_char_p]
lib.zyre_peer_header_value.restype = POINTER(c_char)
lib.zyre_peer_header_value.argtypes = [zyre_p, c_char_p, c_char_p]
lib.zyre_require_peer.restype = c_int
lib.zyre_require_peer.argtypes = [zyre_p, c_char_p, c_char_p, c_char_p]
lib.zyre_socket.restype = czmq.zsock_p
lib.zyre_socket.argtypes = [zyre_p]
lib.zyre_print.restype = None
lib.zyre_print.argtypes = [zyre_p]
lib.zyre_version.restype = c_long
lib.zyre_version.argtypes = []
lib.zyre_test.restype = None
lib.zyre_test.argtypes = [c_bool]

class Zyre(object):
    """
    An open-source framework for proximity-based P2P apps
    """

    allow_destruct = False
    def __init__(self, *args):
        """
        Constructor, creates a new Zyre node. Note that until you start the
node it is silent and invisible to other nodes on the network.
The node name is provided to other nodes during discovery. If you
specify NULL, Zyre generates a randomized node name from the UUID.
        """
        if len(args) == 2 and type(args[0]) is c_void_p and isinstance(args[1], bool):
            self._as_parameter_ = cast(args[0], zyre_p) # Conversion from raw type to binding
            self.allow_destruct = args[1] # This is a 'fresh' value, owned by us
        elif len(args) == 2 and type(args[0]) is zyre_p and isinstance(args[1], bool):
            self._as_parameter_ = args[0] # Conversion from raw type to binding
            self.allow_destruct = args[1] # This is a 'fresh' value, owned by us
        else:
            assert(len(args) == 1)
            self._as_parameter_ = lib.zyre_new(args[0]) # Creation of new raw type
            self.allow_destruct = True

    def __del__(self):
        """
        Destructor, destroys a Zyre node. When you destroy a node, any
messages it is sending or receiving will be discarded.
        """
        if self.allow_destruct:
            lib.zyre_destroy(byref(self._as_parameter_))

    def __eq__(self, other):
        if type(other) == type(self):
            return other.c_address() == self.c_address()
        elif type(other) == c_void_p:
            return other.value == self.c_address()

    def c_address(self):
        """
        Return the address of the object pointer in c.  Useful for comparison.
        """
        return addressof(self._as_parameter_.contents)

    def __bool__(self):
        "Determine whether the object is valid by converting to boolean" # Python 3
        return self._as_parameter_.__bool__()

    def __nonzero__(self):
        "Determine whether the object is valid by converting to boolean" # Python 2
        return self._as_parameter_.__nonzero__()

    def uuid(self):
        """
        Return our node UUID string, after successful initialization
        """
        return lib.zyre_uuid(self._as_parameter_)

    def name(self):
        """
        Return our node name, after successful initialization. First 6
characters of UUID by default.
        """
        return lib.zyre_name(self._as_parameter_)

    def set_name(self, name):
        """
        Set the public name of this node overriding the default. The name is
provide during discovery and come in each ENTER message.
        """
        return lib.zyre_set_name(self._as_parameter_, name)

    def set_header(self, name, format, *args):
        """
        Set node header; these are provided to other nodes during discovery
and come in each ENTER message.
        """
        return lib.zyre_set_header(self._as_parameter_, name, format, *args)

    def set_verbose(self):
        """
        Set verbose mode; this tells the node to log all traffic as well as
all major events.
        """
        return lib.zyre_set_verbose(self._as_parameter_)

    def set_port(self, port_nbr):
        """
        Set UDP beacon discovery port; defaults to 5670, this call overrides
that so you can create independent clusters on the same network, for
e.g. development vs. production. Has no effect after zyre_start().
        """
        return lib.zyre_set_port(self._as_parameter_, port_nbr)

    def set_evasive_timeout(self, interval):
        """
        Set the peer evasiveness timeout, in milliseconds. Default is 5000.
This can be tuned in order to deal with expected network conditions
and the response time expected by the application. This is tied to
the beacon interval and rate of messages received.
        """
        return lib.zyre_set_evasive_timeout(self._as_parameter_, interval)

    def set_expired_timeout(self, interval):
        """
        Set the peer expiration timeout, in milliseconds. Default is 30000.
This can be tuned in order to deal with expected network conditions
and the response time expected by the application. This is tied to
the beacon interval and rate of messages received.
        """
        return lib.zyre_set_expired_timeout(self._as_parameter_, interval)

    def set_interval(self, interval):
        """
        Set UDP beacon discovery interval, in milliseconds. Default is instant
beacon exploration followed by pinging every 1,000 msecs.
        """
        return lib.zyre_set_interval(self._as_parameter_, interval)

    def set_interface(self, value):
        """
        Set network interface for UDP beacons. If you do not set this, CZMQ will
choose an interface for you. On boxes with several interfaces you should
specify which one you want to use, or strange things can happen.
        """
        return lib.zyre_set_interface(self._as_parameter_, value)

    def set_endpoint(self, format, *args):
        """
        By default, Zyre binds to an ephemeral TCP port and broadcasts the local
host name using UDP beaconing. When you call this method, Zyre will use
gossip discovery instead of UDP beaconing. You MUST set-up the gossip
service separately using zyre_gossip_bind() and _connect(). Note that the
endpoint MUST be valid for both bind and connect operations. You can use
inproc://, ipc://, or tcp:// transports (for tcp://, use an IP address
that is meaningful to remote as well as local nodes). Returns 0 if
the bind was successful, else -1.
        """
        return lib.zyre_set_endpoint(self._as_parameter_, format, *args)

    def set_advertised_endpoint(self, value):
        """
        Set an alternative endpoint value when using GOSSIP ONLY. This is useful
if you're advertising an endpoint behind a NAT.
        """
        return lib.zyre_set_advertised_endpoint(self._as_parameter_, value)

    def set_zcert(self, zcert):
        """
        Apply a azcert to a Zyre node.
        """
        return lib.zyre_set_zcert(self._as_parameter_, zcert)

    def set_zap_domain(self, domain):
        """
        Specify the ZAP domain (for use with CURVE).
        """
        return lib.zyre_set_zap_domain(self._as_parameter_, domain)

    def gossip_bind(self, format, *args):
        """
        Set-up gossip discovery of other nodes. At least one node in the cluster
must bind to a well-known gossip endpoint, so other nodes can connect to
it. Note that gossip endpoints are completely distinct from Zyre node
endpoints, and should not overlap (they can use the same transport).
        """
        return lib.zyre_gossip_bind(self._as_parameter_, format, *args)

    def gossip_connect(self, format, *args):
        """
        Set-up gossip discovery of other nodes. A node may connect to multiple
other nodes, for redundancy paths. For details of the gossip network
design, see the CZMQ zgossip class.
        """
        return lib.zyre_gossip_connect(self._as_parameter_, format, *args)

    def gossip_connect_curve(self, public_key, format, *args):
        """
        Set-up gossip discovery with CURVE enabled.
        """
        return lib.zyre_gossip_connect_curve(self._as_parameter_, public_key, format, *args)

    def start(self):
        """
        Start node, after setting header values. When you start a node it
begins discovery and connection. Returns 0 if OK, -1 if it wasn't
possible to start the node.
        """
        return lib.zyre_start(self._as_parameter_)

    def stop(self):
        """
        Stop node; this signals to other peers that this node will go away.
This is polite; however you can also just destroy the node without
stopping it.
        """
        return lib.zyre_stop(self._as_parameter_)

    def join(self, group):
        """
        Join a named group; after joining a group you can send messages to
the group and all Zyre nodes in that group will receive them.
        """
        return lib.zyre_join(self._as_parameter_, group)

    def leave(self, group):
        """
        Leave a group
        """
        return lib.zyre_leave(self._as_parameter_, group)

    def recv(self):
        """
        Receive next message from network; the message may be a control
message (ENTER, EXIT, JOIN, LEAVE) or data (WHISPER, SHOUT).
Returns zmsg_t object, or NULL if interrupted
        """
        return czmq.Zmsg(lib.zyre_recv(self._as_parameter_), True)

    def whisper(self, peer, msg_p):
        """
        Send message to single peer, specified as a UUID string
Destroys message after sending
        """
        return lib.zyre_whisper(self._as_parameter_, peer, byref(czmq.zmsg_p.from_param(msg_p)))

    def shout(self, group, msg_p):
        """
        Send message to a named group
Destroys message after sending
        """
        return lib.zyre_shout(self._as_parameter_, group, byref(czmq.zmsg_p.from_param(msg_p)))

    def whispers(self, peer, format, *args):
        """
        Send formatted string to a single peer specified as UUID string
        """
        return lib.zyre_whispers(self._as_parameter_, peer, format, *args)

    def shouts(self, group, format, *args):
        """
        Send formatted string to a named group
        """
        return lib.zyre_shouts(self._as_parameter_, group, format, *args)

    def peers(self):
        """
        Return zlist of current peer ids.
        """
        return czmq.Zlist(lib.zyre_peers(self._as_parameter_), True)

    def peers_by_group(self, name):
        """
        Return zlist of current peers of this group.
        """
        return czmq.Zlist(lib.zyre_peers_by_group(self._as_parameter_, name), True)

    def own_groups(self):
        """
        Return zlist of currently joined groups.
        """
        return czmq.Zlist(lib.zyre_own_groups(self._as_parameter_), True)

    def peer_groups(self):
        """
        Return zlist of groups known through connected peers.
        """
        return czmq.Zlist(lib.zyre_peer_groups(self._as_parameter_), True)

    def peer_address(self, peer):
        """
        Return the endpoint of a connected peer.
Returns empty string if peer does not exist.
        """
        return return_fresh_string(lib.zyre_peer_address(self._as_parameter_, peer))

    def peer_header_value(self, peer, name):
        """
        Return the value of a header of a conected peer.
Returns null if peer or key doesn't exits.
        """
        return return_fresh_string(lib.zyre_peer_header_value(self._as_parameter_, peer, name))

    def require_peer(self, uuid, endpoint, public_key):
        """
        Explicitly connect to a peer
        """
        return lib.zyre_require_peer(self._as_parameter_, uuid, endpoint, public_key)

    def socket(self):
        """
        Return socket for talking to the Zyre node, for polling
        """
        return czmq.Zsock(lib.zyre_socket(self._as_parameter_), False)

    def print(self):
        """
        Print zyre node information to stdout
        """
        return lib.zyre_print(self._as_parameter_)

    @staticmethod
    def version():
        """
        Return the Zyre version for run-time API detection; returns
major * 10000 + minor * 100 + patch, as a single integer.
        """
        return lib.zyre_version()

    @staticmethod
    def test(verbose):
        """
        Self test of this class.
        """
        return lib.zyre_test(verbose)


# zyre event
lib.zyre_event_new.restype = zyre_event_p
lib.zyre_event_new.argtypes = [zyre_p]
lib.zyre_event_destroy.restype = None
lib.zyre_event_destroy.argtypes = [POINTER(zyre_event_p)]
lib.zyre_event_type.restype = c_char_p
lib.zyre_event_type.argtypes = [zyre_event_p]
lib.zyre_event_peer_uuid.restype = c_char_p
lib.zyre_event_peer_uuid.argtypes = [zyre_event_p]
lib.zyre_event_peer_name.restype = c_char_p
lib.zyre_event_peer_name.argtypes = [zyre_event_p]
lib.zyre_event_peer_addr.restype = c_char_p
lib.zyre_event_peer_addr.argtypes = [zyre_event_p]
lib.zyre_event_headers.restype = czmq.zhash_p
lib.zyre_event_headers.argtypes = [zyre_event_p]
lib.zyre_event_header.restype = c_char_p
lib.zyre_event_header.argtypes = [zyre_event_p, c_char_p]
lib.zyre_event_group.restype = c_char_p
lib.zyre_event_group.argtypes = [zyre_event_p]
lib.zyre_event_msg.restype = czmq.zmsg_p
lib.zyre_event_msg.argtypes = [zyre_event_p]
lib.zyre_event_get_msg.restype = czmq.zmsg_p
lib.zyre_event_get_msg.argtypes = [zyre_event_p]
lib.zyre_event_print.restype = None
lib.zyre_event_print.argtypes = [zyre_event_p]
lib.zyre_event_test.restype = None
lib.zyre_event_test.argtypes = [c_bool]

class ZyreEvent(object):
    """
    Parsing Zyre messages
    """

    allow_destruct = False
    def __init__(self, *args):
        """
        Constructor: receive an event from the zyre node, wraps zyre_recv.
The event may be a control message (ENTER, EXIT, JOIN, LEAVE) or
data (WHISPER, SHOUT).
        """
        if len(args) == 2 and type(args[0]) is c_void_p and isinstance(args[1], bool):
            self._as_parameter_ = cast(args[0], zyre_event_p) # Conversion from raw type to binding
            self.allow_destruct = args[1] # This is a 'fresh' value, owned by us
        elif len(args) == 2 and type(args[0]) is zyre_event_p and isinstance(args[1], bool):
            self._as_parameter_ = args[0] # Conversion from raw type to binding
            self.allow_destruct = args[1] # This is a 'fresh' value, owned by us
        else:
            assert(len(args) == 1)
            self._as_parameter_ = lib.zyre_event_new(args[0]) # Creation of new raw type
            self.allow_destruct = True

    def __del__(self):
        """
        Destructor; destroys an event instance
        """
        if self.allow_destruct:
            lib.zyre_event_destroy(byref(self._as_parameter_))

    def __eq__(self, other):
        if type(other) == type(self):
            return other.c_address() == self.c_address()
        elif type(other) == c_void_p:
            return other.value == self.c_address()

    def c_address(self):
        """
        Return the address of the object pointer in c.  Useful for comparison.
        """
        return addressof(self._as_parameter_.contents)

    def __bool__(self):
        "Determine whether the object is valid by converting to boolean" # Python 3
        return self._as_parameter_.__bool__()

    def __nonzero__(self):
        "Determine whether the object is valid by converting to boolean" # Python 2
        return self._as_parameter_.__nonzero__()

    def type(self):
        """
        Returns event type, as printable uppercase string. Choices are:
"ENTER", "EXIT", "JOIN", "LEAVE", "EVASIVE", "WHISPER" and "SHOUT"
and for the local node: "STOP"
        """
        return lib.zyre_event_type(self._as_parameter_)

    def peer_uuid(self):
        """
        Return the sending peer's uuid as a string
        """
        return lib.zyre_event_peer_uuid(self._as_parameter_)

    def peer_name(self):
        """
        Return the sending peer's public name as a string
        """
        return lib.zyre_event_peer_name(self._as_parameter_)

    def peer_addr(self):
        """
        Return the sending peer's ipaddress as a string
        """
        return lib.zyre_event_peer_addr(self._as_parameter_)

    def headers(self):
        """
        Returns the event headers, or NULL if there are none
        """
        return czmq.Zhash(lib.zyre_event_headers(self._as_parameter_), False)

    def header(self, name):
        """
        Returns value of a header from the message headers
obtained by ENTER. Return NULL if no value was found.
        """
        return lib.zyre_event_header(self._as_parameter_, name)

    def group(self):
        """
        Returns the group name that a SHOUT event was sent to
        """
        return lib.zyre_event_group(self._as_parameter_)

    def msg(self):
        """
        Returns the incoming message payload; the caller can modify the
message but does not own it and should not destroy it.
        """
        return czmq.Zmsg(lib.zyre_event_msg(self._as_parameter_), False)

    def get_msg(self):
        """
        Returns the incoming message payload, and pass ownership to the
caller. The caller must destroy the message when finished with it.
After called on the given event, further calls will return NULL.
        """
        return czmq.Zmsg(lib.zyre_event_get_msg(self._as_parameter_), True)

    def print(self):
        """
        Print event to zsys log
        """
        return lib.zyre_event_print(self._as_parameter_)

    @staticmethod
    def test(verbose):
        """
        Self test of this class.
        """
        return lib.zyre_event_test(verbose)

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
