inherit ROOM;

void create()
{
        set("short", "�ᶽ��");
        set("long", @LONG
��������ᶽ���˰칫�µĵط�����ǰ������ľ������
���������ŵģ����ǳɶ��ᶽ����¡�����վ���Ʒ粻������
�����ױ��̴ӣ�����ȥ��ʮ�ֱ뺷��
LONG);
        set("exits", ([
            	"south" : __DIR__"tidugate",
        ]));
        set("objects", ([
             	__DIR__"npc/wutiande" : 1,
             	__DIR__"npc/shicong"  : 2,
             	__DIR__"npc/qinbing" : 4,
        ]));
        setup();
        replace_program(ROOM);
}
