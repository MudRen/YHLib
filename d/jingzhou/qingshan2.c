inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
˳ɽ���ߣ�ɽ�ƽ��������������Ӳݾ��������� ʹ����
�����ߡ�
LONG);
        set("exits", ([
                "westup" : __DIR__"qingshan",
                "eastdown" : __DIR__"road4",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}

