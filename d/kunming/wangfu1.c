inherit ROOM;

void create()
{
        set("short",  "������Ժ" );
        set("long", @LONG
�������ƽ�������Ĵ�Ժ��Ժ�������˸��ӻ��ݣ�������
��ȴ���м��һ������ɽ�裬�޴�������Ͽ�����������ɽ��
������ɫ��ǳ��һ������̺죬ʮ�ֺÿ���
LONG);
        set("outdoors", "kunming");
        set("exits", ([
                "south"    :__DIR__"wangfu",
                "north"   :__DIR__"wangfu2",
                "west"   :__DIR__"xizoulang",
                "east"   :__DIR__"dongzoulang"
        ]));
        set("objects", ([
                "/d/shaolin/npc/shang1" : 1,
        ]));
        setup();
        replace_program(ROOM);         
}
