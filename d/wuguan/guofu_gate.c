inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��������");
	set("long", 
"�������ӵĴ�լԺ�����������ǰ��ֻ����¥��������ǰ
��������ʯʨ������������������" YEL "

              ����������������������
              ��                  ��
              ��" NOR + HIY "     ��    ��" NOR + YEL "     ��
              ��                  ��
              ����������������������" NOR "

��Ӵ����ƽ�ȥ�����������������������ܷ�æ�����ӡ�����
վ��λ���꣬�������ϡ��Ӵ�ǰ�����������ĸ�����ʿ��
");
        set("outdoors", "xiangyang");
	set("exits", ([
		"south" : "/d/xiangyang/westjie1",
		"north" : __DIR__"guofu_dayuan",
	]));
	set("objects", ([
		__DIR__"npc/wudunru" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        if (me->query("mark/guofu_ok")
           && present("wu dunru", environment(me)) 
           && dir == "south")
             return notify_fail(CYN "\n��������ֽ�����ס��������"
                                "�������ڲ�̫ƽ���㻹�Ƕ��һ���"
                                "��\n" NOR);

        if (me->query("mark/guofu_over")
           && present("wu dunru", environment(me))
           && dir == "north")
             return notify_fail(CYN "\n����彫����ס����Ц������"
                                "�����㲻�£��㻹���߰ɡ�\n" NOR);

        if (me->query("mark/guofu_out")
           && present("wu dunru", environment(me)) 
           && dir == "north")
             return notify_fail(CYN "\n�����Ц�����������ڹ�����"
                                "�޶����ô������Ƕ�ȥ����������"
                                "��\n" NOR);

        if (me->query("combat_exp") > 5000
           && ! me->query("mark/guofu_ok")
           && present("wu dunru", environment(me)) 
           && dir == "north")
             return notify_fail(CYN "\n����屧ȭ������������ֵ��"
                                "��ʱ�ڣ�ûʦ����ɣ��κ��˲�����"
                                "�ڡ�\n" NOR);

        if (! me->query("mark/guofu_ok")
           && present("wu dunru", environment(me)) 
           && dir == "north")
             return notify_fail(CYN "\n��������ֽ�����ס�������"
                                "�㲻�����æ���ӣ��ͱ������\n" NOR);

        return ::valid_leave(me, dir);
}
