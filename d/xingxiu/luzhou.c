inherit ROOM;

void create()
{
        set("short", "ɳĮ����");
        set("long", @LONG
�������˵أ�������ɳĮ�ľ�ͷ������һ�����ޡ���ľ��
����һ�ۿ���������̨����һ��ľ��ר���ڿʵ����˺�ˮ����
����һ��ϵء�
LONG);
        set("resource/water", 1);
        set("exits", ([
                "northeast" : __DIR__"shanjiao",
                "southwest" : __DIR__"nanjiang3",
        ]));

        set("objects", ([
            	__DIR__"obj/hamigua" : 2,
        ]));

        set("outdoors", "xiyu");
        set("no_map", "����ĵ��������Ի��޷����Ƶ�ͼ��\n");
        setup();
}
