inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
�����Ǵ����ڣ�������һ��������·�ϣ����˶��Ǳ���
�İ������ˡ�Ҳ�����Щ��ԭ���������߶�����·����ͨ��
�ٵ�����������·ͨ������ǵ����ţ����пɴ�㶫��ɽ��
LONG);
        set("objects", ([
                "/clone/quarry/tu" : 2,
        ]));
        set("outdoors", "dali");
        set("exits", ([
                "northwest" : __DIR__"shuangheqiao",
                "southeast" : "/d/foshan/road1",
        ]));
        setup();
        replace_program(ROOM);
}

