inherit ROOM;

void create()
{
        set("short", "�����ڲ�");
        set("long", @LONG
���߽�������������ǽ�ڶ�����������ɣ�������һ��
�޼ʵ����֡���������Ρ����̾�Ϊ���ơ���һ���˱Ƕ�����
������ζ��ȴ�Ե��������ŵ����׸���롣
LONG);
        set("exits", ([
                "out" : __DIR__"pomiao"
        ]));

	set("objects", ([
		CLASS_D("gaibang") + "/hong" : 1,
	]));

        set("valid_startroom", 1);
        set("sleep_room", 1);
        setup();
        replace_program(ROOM);
}

