inherit ROOM;

void create()
{
        set("short", "���϶�");
        set("long", @LONG
����Ƕ��ҵ�һ�󶴣���������ޱȣ������Ѳ⡣��һ��
�������㷢�����в�涴�����Թ�������Ī�⣬�ƺ�����޵ס�
��������������Ȯ����֮�������˾���䣬��������Ⱥӿ����
��Ϩ��档���ǿ���뿪�ɡ�
LONG);
        set("objects", ([
                "/clone/quarry/fu" : 3,
        ]));
        set("exits", ([
                "south" : __DIR__"jiulaodong",
        ]));

        setup();
        replace_program(ROOM);
}
