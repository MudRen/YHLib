#include <ansi.h>
inherit ROOM;

string look_gate();

void create()
{
        set("short", "������ɽ��");
        set("long", @LONG
������Ϊ���ҳ���֮�Ż���ɽ��(gate)����һ����ҡ���
���骻����������ӳ���ɴ�һ·�����Ͽ�ʼ�Ƕ���ɽ������
��ɽ��һ�������ʯ��·��
LONG);
        set("outdoors", "emei");
        set("item_desc", ([
                "gate" : (: look_gate :),
        ]));
        set("objects", ([
                __DIR__"npc/guest": 1,
        ]));
        set("exits", ([
                "northdown" : __DIR__"qsjie2",
                "south"     : __DIR__"bgs",
        ]));
        setup();
        replace_program(ROOM);
}

string look_gate()
{
      return
RED "\n\n���������աաաաաաաաաաաաաաաա�\n"
"���������աա��������������������������ա�\n"
"���������ա�" WHT "��������������������" RED "�������ա�\n"
"���������աա��������������������������ա�\n"
"���������աաաաաաաաաաաաաաաա�\n\n\n";
}
