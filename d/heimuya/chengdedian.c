#include <ansi.h>;
inherit ROOM;

void create()
{
  	set("short", "�ɵµ�");
  	set("long",
"�����������̽���ƽ�շ���ʩ��ĵط��������޴�����
�ڵ������λε����򣬴��˶˸���һ������������һ���׷�
���ߣ��������𽭺���������̽����������ˡ��������Ϸ���
��һ����ң�д���������ҫ�۵Ĵ��֣�

           " HIW "��������������������������������
           ��                            ��
           ��" NOR + HIR "     ��      ��      ��" NOR + HIW "     ��
           ��                            ��
           ��������������������������������" NOR "

��������վ����������̵ĵ��Ӻ��̴ӣ���������������ѵ��\n
");
  	set("valid_startroom", 1);
  	set("exits",([
      		"north" : __DIR__"zoulang",
      		"south" : __DIR__"shanya1",
  	]));
        set("objects", ([
                CLASS_D("riyue") + "/ren" : 1,
      		__DIR__"npc/dizi" : 4,
        ]));
  	setup();
  	"/clone/board/riyue_b"->foo();
}

int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me = this_player();

        if (dir != "south")
        {
                if ((string)me->query("family/family_name") != "�������"
                & objectp(present("ren woxing", environment(me))))
                        return notify_fail(CYN "�����кȵ�������δ��̫����������"
                                           "�Ϸ���ǰҲ�������У�\n" NOR);
        }
        return ::valid_leave(me, dir);
}
