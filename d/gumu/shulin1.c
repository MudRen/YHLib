
inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
����һƬС���֣���Χ����ľ���ܸߡ�������һЩ�в���
���ֵ��ʻ�������ͷס�����������Щ����������������·��
�ɣ�תͷ��ȴ�������ϱ��ƺ���һ��С·������������֮�С�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northdown" : __DIR__"shulin0",
                "southwest" : __DIR__"shulin2",
        ]));

        setup();
        replace_program(ROOM);
}
