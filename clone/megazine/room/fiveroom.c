#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIW "����������־���糤�칫��" NOR);
	set("long", @LONG
�����ǡ���������־���糤����İ칫�ң�����Կ�����ǽ�Ϲ�������
��Ƭ(picture)����д��̨����������Ƭ(card),�������ʲô�£��Ϳ�����
������ϵ���칫���������糤����Ϣ�ң�����ò�Ҫȥ��������
LONG
	);

	set("exits", ([ 
                "down" : __DIR__"fourroom",
                "enter" : __DIR__"myhome",
        ]));

        set("item_desc", ([
                "card"    : HIG "��� E-MAIL:wfoxd@sina.com  OICQ:47611\n" NOR,
                "picture" : HIG "���ϵ����ﳤ�����������ٷ磬�������Σ�����֮�䣬��ɷ���������������\n" NOR,
        ]));

        set("no_fight",1);   
	setup();
}

int valid_leave(object me, string dir) 
{
        object ob = this_player();

        if (ob->query("id") == "wfoxd" && dir == "enter") 
        {
                message_vision(HIG "$N�ó���һ�����̵�Կ�ף�����ذ��Ŵ򿪣����ݵ����˽�ȥ��\n" NOR, me); 
                return ::valid_leave(me, dir); 
        }

        if (ob->query("id") == "miller" && dir == "enter") 
        {
                message_vision(HIG "$N�ó���һ�����̵�Կ�ף�����ذ��Ŵ򿪣����ݵ����˽�ȥ��\n" NOR, me);  
                return ::valid_leave(me, dir);  
        }

        if (dir == "enter") 
                return notify_fail(HIW "��ֻ������˷��Ŀ�����һ�����ε������������γ���һ��������ǽ��ס�����ȥ·��\n" NOR);

        if (dir == "down")
                message_vision(HIG "$N�������ض���������һ���������ûʲô��ˮ����,���������뿪�ˡ�\n" NOR, me);

        return ::valid_leave(me, dir);
}
