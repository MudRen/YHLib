#include <ansi.h>
inherit ROOM;

string look_ta();

void create()
{
        set("short", "������");
        set("long", @LONG
�������Ƕ�üɽ��Ĵ���Ժ֮һ��������ɽ���죬���յ�
���۵�߷�������ߣ���ģ��󡣵��ڷ�������������
���������ڷ����Ծ���������������������������(ta)������
������Լ����ɴ�����¡�
LONG);
        set("outdoors", "emei");
        set("item_desc", ([
                "ta" : (: look_ta :),
        ]));
        set("objects", ([
                __DIR__"npc/guest": 1,
        ]));
        set("exits", ([
                "west"  : __DIR__"bgsxq",
                "enter" : __DIR__"dxdian",
                "north" : __DIR__"bgsgate",
                "south" : __DIR__"milin1",
        ]));
        setup();
        replace_program(ROOM);
}

string look_ta()
{
        return YEL "\n����һ��ʮ������ͭ����������������"
               "�ף��������ѹ���С\n����ǧ�߰���֮�࣬����"
               "�С����Ͼ���ȫ��������֣���ұ��\n�������"
               "�����ɣ�������������֮����\n\n" NOR;
}
