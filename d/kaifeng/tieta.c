inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������ʮ���ף��˽�ʮ���㡣����˵�Ϊ�ο����£�����
��������������������Ϊ��ɫ����ש���ɻ�˽����������׳�
��Ϊ�����������޳���������ΰ��ש�����Է��졢�����ּ�
����ʮ��ͼ��������������
LONG);
        set("outdoors", "kaifeng");
        set("exits", ([
		"west" : __DIR__"jieying",
		"east" : __DIR__"eroad3",
	]));
        set("objects", ([
                CLASS_D("honghua") + "/luo" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
