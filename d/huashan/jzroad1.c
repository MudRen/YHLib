inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һƬ�����֡��м�һ��С·�����߶��Ǻ�ɭɭ�ļ���
�ߵ����������Ͻ��Ų����ɹ��������Ұ�������ζ�����
LONG );
        set("exits", ([
                "southwest" : "/d/village/hsroad2",
                "east"      : __DIR__"jzroad2",
        ]));
        set("objects", ([
                "/clone/quarry/tu" : 2,
        ]));
        set("outdoors", "huashan");
        setup();
        replace_program(ROOM);
}
