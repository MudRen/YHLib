inherit ROOM;

#include "langqun.h"

void create()
{
        set("short", "�߲�����");
        set("long", @LONG
վ������һ����ȥ���߸߰����ķ����α��۴Σ�������Ϣ
ȫ�ޣ�����ȸ�����֮����˿�����š���˿ɲ��ľ��󣬼ž�
������ʹ��������Ҳ���Ҵ���һ�ڡ�һƬ�ž�֮�У�Զ����Ȼ
�������������ơ�
LONG);
        set("outdoors", "gaochang");
        set("exits", ([ 
                "east" : __DIR__"feixu1",
                "west" : __DIR__"pendi",
		"north" : __DIR__"xiaowu",
	]));

        setup();
}
