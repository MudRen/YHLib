#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��紨");
        set("long", @LONG
����վ��һ�龧Ө��͸���������֮�ϣ�ֻ���Ų����ϴ���
һ��͸�ǵı�����ѩɽ�ϱ���ŭ�ţ�������Ƶ�������ѩ����
��һƬ��ã���Ѿ�������������������ˡ�ƬƬѩ���ӿ��ж�ë
��������¡�����ﻬ����·������춱��ϡ���ν��ѩ���ѣ���
�������족��
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            	"southdown"  : __DIR__"shiya",
            	"northup"  : __DIR__"sroad5",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
