#include <ansi.h>
inherit ROOM;

void home(object ob);

void create()
{
        set("short", "��̲");
        set("long", @LONG
��������������ˡ��ϱ���һ���޼ʵĴ󺣣���������Ƭ
��ľ�֡����ϵĿ����ƺ��������ƣ���ʪ�ĺ����д���һ����
�����ּ�����һ�����صĻ��㣬����������ʮ�ֹ��졣���߻�
����һ�Ҵ�(chuan)��
LONG);

        set("item_desc", ([
                "chuan" : "����������������ϵ�Ĵ󴬡����ϵĿ��˻����ֻҪ\n"
                          "�ϴ�(enter)�Ϳ��Ի���ԭ��\n",
        ]));
        set("exits",([
                "north" :__DIR__"lin1",
        ]));
        set("outdoors", "shenlong");
        setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter ( string arg )
{
        object ob;
        string dir;

        ob = this_player();
        if (arg != "chuan")
        {
                tell_object(ob , "��Ҫ enter �Ķ���\n");
                return 1 ;
        }

        message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
        message_vision("�������𷫣��������������С�\n", ob);
        ob ->move(__DIR__"dahai") ;
        tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR);
        call_out("home", 10 , ob);
        return 1 ;
}

void home(object ob)
{
        if (! objectp(ob) || find_object(__DIR__"dahai") != environment(ob))
                return;

        tell_object(ob, "�����ڵִ�����ԭ��һ���������С������´�����\n");
        ob->move("/b/tulong/haigang");
}

