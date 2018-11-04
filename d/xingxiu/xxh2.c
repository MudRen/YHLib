#include <ansi.h>
inherit ROOM;

string look_duilian();

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ
���ն�������������ͨ�����޺�������ϱ����������ܶ�
���¶������ڹ���һ������(duilian)��
LONG);
        set("exits", ([
             	"north" : __DIR__"riyuedong",
             	"south" : __DIR__"xxh1",
             	"northeast" : __DIR__"xxh3",
             	"northwest" : __DIR__"xxh4",
        ]));

        set("valid_startroom",1);
        set("item_desc", ([
                "duilian" : (: look_duilian :),
        ]));
        
        set("objects", ([
                 "/kungfu/class/xingxiu/dizi" : 4,
        ]));

        set("outdoors", "xingxiu");
        setup();
        "/clone/board/xingxiu_b"->foo();
}

string look_duilian()
{
        return
        RED "\n"
        "        ��������������            ��������������\n"
        "        ��������������            ��������������\n"
        "        ����      ����            ����      ����\n"
        "        ����" NOR + HIW "���ǡ�" NOR + RED "����            ����" NOR + HIW "  ��  " NOR + RED "����\n"
        "        ������ �� ����            ����      ����\n"
        "        ����" NOR + HIW "  ��  " NOR + RED "����            ����" NOR + HIW "  ��  " NOR + RED "����\n"
        "        ����      ����            ����      ����\n"
        "        ����" NOR + HIW "  ��  " NOR + RED "����            ����" NOR + HIW "  ��  " NOR + RED "����\n"
        "        ����      ����            ����      ����\n"
        "        ����" NOR + HIW "  ��  " NOR + RED "����            ����" NOR + HIW "  ��  " NOR + RED "����\n"
        "        ����      ����            ����      ����\n"
        "        ����" NOR + HIW "  ��  " NOR + RED "����            ����" NOR + HIW "  ��  " NOR + RED "����\n"
        "        ����    ������            ����      ����\n"
        "        ��������������            ��������������\n"
        "        ��������������            ��������������\n\n\n" NOR;
}

int valid_leave(object me, string dir)
{
        object guarder;

        if (! objectp(guarder = present("xingxiu dizi", this_object())))
                return 1;

        if (dir == "north")
                return guarder->permit_pass(me, dir);
        

        return 1;
}
