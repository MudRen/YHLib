inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ƿǳ����ɵĳ��ȡ������Ǽ���Ϣ�ҡ��ϱ���һ��С
С��ҩ�������洫��һ�������������������������ȹ����γ�
�š���������������
LONG);
        set("exits", ([
                "west"  : __DIR__"ximen",
                "east"  : __DIR__"liangong",
                "north" : __DIR__"restroom",
                "south" : __DIR__"yaofang",
        ]));

        setup();
        replace_program(ROOM);
}
