inherit ROOM;

void create()
{
        set("short", "ͨ���");
        set("long", @LONG
�����ǹ�������֮ĩ--ͨ������Ĵ����ڵ����̲���
��ʢ����ͨ������Ľ����Աߣ����ż�λ�ؽ̵��ѣ��󳤶��ɡ�
�����ɡ��깫��������
LONG);
        set("exits", ([
                "north" : __DIR__"laojundian",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
