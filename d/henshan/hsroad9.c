inherit ROOM;

void create()
{
        set("short", "����ɽ��");
        set("long", @LONG
�����������һ��ɽ�ڡ����������ϵĴ����ɽ��������
���ϵĵؽ硣���Ϲ㶫������ʢ�����к���֮ʿ��
LONG );
        set("outdoors", "hengyang");

        set("exits", ([
                "northdown" : __DIR__"hsroad5",
                "southdown" : "/d/foshan/nanling",
        ]));
        setup();
        replace_program(ROOM);
}
