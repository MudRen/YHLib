inherit ROOM;

void create()
{
        set("short", "�¶�Ȫ");
        set("long", @LONG
�����������֮�⣬��ɳĮ�о�Ȼ��Ȫˮ��һ���峺��Ȫ
ˮ�γ�һ����������״����������¶�Ȫ��������һƬ�ͱڶ�
�ߴ������˵����졣
LONG );
        set("resource/water", 1);
        set("exits", ([
                "east" : __DIR__"shashan",
                "enter" : __DIR__"mogaoku",
        ]));
        set("no_clean_up", 0);
        setup();
}