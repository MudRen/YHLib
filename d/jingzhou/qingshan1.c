inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
˳ɽ���ߣ�ɽ�ƽ��������������Ӳݾ��������� ʹ����
�����ߡ�
LONG);
        set("exits", ([
                "southwest" : __DIR__"road5",
                "eastup" : __DIR__"qingshan",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}

