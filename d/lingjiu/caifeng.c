inherit ROOM;

void create()
{
        set("short", "�����");
        set("long",@LONG
������翷����չ��Ĳ÷��ҡ�����Ů��Χ����һ�飬����
���ߣ�����Ů�죬Ϊ���չ������Ů���ӷ������¶��� 
LONG);
        set("exits", ([
                "south" : __DIR__"changl10",
        ]));
        set("objects",([
                CLASS_D("lingjiu") + "/fumingyi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
