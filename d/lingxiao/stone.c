inherit ROOM;

void create()
{
        set("short", "�ƺ�ʯ");
        set("long", @LONG
�������һ��˶���ʯͷ�����ǰ����ڴ�ѩɽ�������ҵ���
��ʯ��ֻ�������������ƣ�������һЩ���ι�״�Ļ��ơ���˵��
Ҫ�����ʱ�򣬻���ɢ������ͬ��״������������ʯ���ܣ���
�ò�ɢ���ǰ�������ϲ��������ı��
LONG );
        set("outdoors", "lingxiao");
        set("exits", ([
            	"east" : __DIR__"meiroad2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}