
inherit ROOM;

void create()
{
        set("short", "�ڷﶴ");
        set("long", @LONG
�˴�λ�����ɽ��������̫��ɽ�ϡ�ɽ��ֱ��ֱ�£���
�а�Ķ��ͣ�ɽ������һ�������Ӵֵ�ʯ������ʱð��һ�ɺ�
�����ֿ��µġ�������һƬ���֡�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "westup"  : __DIR__"shulin7",
        ]));

        setup();
        replace_program(ROOM);
}
