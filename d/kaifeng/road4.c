inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����߸ߵ�����ͬ�ʺ�����˼䣬��ʮ����ʯ��ֱͨ����
���¾���ˮ����ӿ�Ĵ��˺ӡ���������������о��ۺ������
Ȼ�����¿�ȥ�������ڸ߲�֮�ϣ������Ĳ����ѡ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"southdown" : __DIR__"road3",
  		"northdown" : __DIR__"road5",
	]));
        set("objects", ([
                CLASS_D("honghua") + "/lu" : 1,
                "/clone/npc/walker" : 1,
        ]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
