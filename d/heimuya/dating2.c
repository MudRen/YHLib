#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�׻���");
        set("long", @LONG
������������µڶ����ð׻��õĴ������ڣ������ڷǳ�
�Ŀ��������������µ���վ�����У���Ŀ��ȥ��һ����Ȼ��
������������һ���ľ��(bian)��
LONG);
        set("exits", ([
            	"west" : __DIR__"baistep1",
            	"east" : __DIR__"baigate",
        ]));
        set("item_desc", ([
                "bian" : WHT "\n\n        ����������������������������\n"
                              "        ��                        ��\n"
                              "        ��   " HIW "��������  �׻�����" NOR + WHT "   ��\n"
                              "        ��                        ��\n"
                              "        ��   " HIW "ǧ������  һͳ����" NOR + WHT "   ��\n"
                              "        ��                        ��\n"
                              "        ����������������������������\n\n\n" NOR,
        ]) );
        set("objects",([
                __DIR__"npc/dizi4" : 4,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
