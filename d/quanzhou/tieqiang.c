inherit ROOM;

void create()
{
	set("short", "��ǹ��");
	set("long", @LONG
����ǹ�����������ʱ������ǹ�����¡���������������
����Ⱥѻ����Ϊ��������˵��ǹ�����ѻ������񽫣�����
�����ַ�������������ֳ��Խ��Խ�ࡣ
LONG);
	set("exits", ([
                "west"  : __DIR__"jxnanmen",
		"north" : __DIR__"nanhu",
        ]));
        setup();
        replace_program(ROOM);
}
