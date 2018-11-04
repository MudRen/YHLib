// analecta.c
// Create by jjgod. 2002/01/27.
// Modify By Linux@lxtx

#include <ansi.h>
#include <mudlib.h>
#include <localtime.h>

#ifndef ANALECTA_D
#define ANALECTA_D      "/adm/daemons/analectad"
#endif

inherit F_CLEAN_UP;

int    help(object me);
string list_analectas(mapping *analectas, int year, object me);
string read_analecta(int year, mapping analecta, int i, object me);
int    sort_analectas(mapping a1, mapping a2);
int    filter_analectas(string analecta, int time);

int main(object me, string arg)
{
        string info, name, id, *all_analecta, dir;
        int year, i;
        object board;
        mapping all_note, analecta;
        mapping *analectas;

        year = localtime(time())[LT_YEAR];
        analectas = ANALECTA_D->query_analecta_list()[sprintf("%d", year)];

        info = HIC + LOCAL_MUD_NAME() + "(" + HIW + upper_case(INTERMUD_MUD_NAME) + 
               HIC + ")����ѡ����\n" NOR WHT "������������������������������������"
               "��������������������������������������������������������\n" NOR;

        // �Ķ�������ѡ
        if (arg == "new" || arg && sscanf(arg, "new %d", year))
        {
                analectas = ANALECTA_D->query_analecta_list()[sprintf("%d", year)];
                if (! arrayp(analectas) || ! sizeof(analectas))
                        info += CYN " ���� " WHT + year + CYN " û���κ��µ���ѡ"
                                "�����Ķ���\n";
                else
                {
                        i = me->query("analecta_last_read/" + year);
                        analectas = sort_array(analectas, (: sort_analectas :));
                        analectas = filter_array(analectas, (: filter_analectas :), i);
                        if (! sizeof(analectas))
                                info += CYN " ���� " WHT + year + CYN " ��û���κ�"
                                        "�µ���ѡ�����Ķ���\n";
                        else
                                info += read_analecta(year, analectas[0], member_array(analectas[0],
                                        ANALECTA_D->query_analecta_list()[sprintf("%d", year)]) + 1, me);
                }
        }
        else
        // �����ѡ
        if (arg && sscanf(arg, "add %d from %s", i, name) == 2)
        {
                if (! wizardp(me))
                        info += CYN " ������Ȩ�������ѡ��\n" NOR;
                else
                if (! objectp(board = present(name, environment(me))))
                        info += CYN " ����û�� " WHT + name + 
                                CYN " ������԰塣\n" NOR;
                else
                {
                        all_note = board->query("notes");
                        if (! arrayp(all_note) || i < 1 || i > sizeof(all_note))
                                info += CYN " û���������ԡ�\n" NOR;
                        else
                        {
                                i--;
                                sscanf(all_note[i]["author"], "%s-%s", name, id);
                                analecta = ([ ]);
                                analecta["subject"] = all_note[i]["title"];
                                analecta["author_name"] = name;
                                analecta["author_id"] = id;
                                analecta["time"] = all_note[i]["time"];
                                analecta["content"] = all_note[i]["msg"];
                                analecta["board"] = board->name();

                                ANALECTA_D->add_analecta(year, analecta);
                                info += CYN " �Ѿ��ɹ��������" + board->name() +
                                        "�� " WHT + (i + 1) + CYN " �����Խ���"
                                        "�������ѡ��\n" NOR;
                        }
                }
        }
        // ɾ����ѡ
        else
        if (arg && sscanf(arg, "del %d %d", year, i) == 2)
        {
                if (! wizardp(me))
                        info += CYN " ������Ȩ��ɾ����ѡ��\n" NOR;
                else
                if (! ANALECTA_D->delete_analecta(year, i))
                        info += CYN " û�� " WHT + year + CYN " �����ȵ���ѡ"
                                "������û�� " WHT + i + CYN " �����ŵ���ѡ"
                                "��\n" NOR;
                else
                        info += CYN " ��� " WHT + year + CYN " ��� " WHT + i +
                                CYN " ����ѡ�Ѿ����ɹ�ɾ����\n" NOR;
        }
        // ת���ɰ汾��ѡ
        if (arg && sscanf(arg, "convert %s", dir))
        {
                if (file_size(dir) != -2)
                        info += CYN " û�� " WHT + dir + CYN " ���Ŀ¼�ɹ�ת��"
                                "��\n";
                else
                {
                        string subject, board_name;
                        int time;
                        int j = 0;

                        all_analecta = get_dir(dir);
                        for (i = 0; i < sizeof(all_analecta); i++)
                        {
                                if (sscanf(all_analecta[i], "%s-%s-%s-%d-%s",
                                    subject, name, id, time, board_name) != 5)
                                {
                                        write(all_analecta[i] + " parse wrong.\n");
                                        continue;
                                }

                                analecta = ([ ]);
                                analecta["subject"] = subject;
                                analecta["author_name"] = name;
                                analecta["author_id"] = id;
                                analecta["time"] = time;
                                analecta["board"] = board_name;
                                analecta["content"] = read_file(dir + all_analecta[i]);

                                year = localtime(time)[LT_YEAR];
                                ANALECTA_D->add_analecta(year, analecta);
                                rm(dir + all_analecta[i]);
                                j++;
                        }
                        info += CYN " Ŀ¼ " WHT + dir + CYN " �µľɰ汾��ѡ��"
                                "���ѱ��ɹ�ת���� " WHT + j + CYN " ����\n" NOR;
                }
        }
        // �г�����ѡ�����
        else
        if (! arrayp(analectas) || ! sizeof(analectas))
        {
                all_analecta = keys(ANALECTA_D->query_analecta_list());
                all_analecta -= ({ sprintf("%d", year) });

                if (! sizeof(all_analecta))
                        info += CYN " ���ڻ�û���κ����±��ռ���\n" NOR;
                else
                {
                        info += sort_string(CYN " ������ " WHT +
                                            implode(all_analecta, CYN "��" WHT) +
                                            CYN " �� " WHT + sizeof(all_analecta) +
                                            CYN " �����ѡ���Ķ���\n" NOR, 86);
                }
        }
        else
        {
                // �б�
                if (! arg)
                {
                        info += CYN "��� " WHT + year + CYN " ����ѡ�У�\n\n" NOR;
                        info += list_analectas(analectas, year, me);
                }
                // �Ķ�ָ����ݵ�����
                else
                if (sscanf(arg, "%d %d", year, i) == 2)
                {
                        analectas = ANALECTA_D->query_analecta_list()[sprintf("%d", year)];
                        if (! arrayp(analectas) || ! sizeof(analectas))
                                info += CYN " û�� " WHT + year + CYN " �����"
                                        "�ȵ���ѡ��\n" NOR;
                        else
                        if (sizeof(analectas) < i)
                                info += CYN " ��� " WHT + year + CYN " û�� "
                                        WHT + i + CYN " �����ŵ���ѡ��\n" NOR;

                        else
                                info += read_analecta(year, analectas[i - 1], i, me);
                }
                // �Ķ���������»����г������������
                else
                if (sscanf(arg, "%d", i))
                {
                        year = localtime(time())[LT_YEAR];
                        analectas = ANALECTA_D->query_analecta_list()[sprintf("%d", i)];
                        if (arrayp(analectas) && sizeof(analectas))
                        {
                                info += CYN "��� " WHT + i + CYN " ����ѡ�У�"
                                        "\n\n" NOR;
                                info += list_analectas(analectas, i, me);
                        }
                        else
                        if (arrayp(ANALECTA_D->query_analecta_list()[sprintf("%d", year)]) &&
                            sizeof(analectas) && sizeof(analectas) >= i)
                                info += read_analecta(year, analectas[i - 1], i, me);

                        else info += CYN " û�� " WHT + i + CYN " �����Ȼ���"
                                     "���������ŵ���ѡ��\n" NOR;
                }
                else return help(me);
        }

        info += WHT "��������������������������������������������������������������"
                "������������������������������" NOR;
        me->start_more(info);
        return 1;
}

// �г���ѡ����
string list_analectas(mapping *analectas, int year, object me)
{
        int i, last;
        mapping analecta;
        string info, is_new;

        info = "";
        last = me->query("analecta_last_read/" + year);
        for (i = 0; i < sizeof(analectas); i++)
        {
                analecta = analectas[i];
                is_new = analecta["add_time"] > last ? HIY : "";
                info += sprintf(CYN " %s[" NOR WHT "%3d" CYN "%s]" NOR
                                CYN " %-36s " WHT "%15s [ " CYN "%s "
                                WHT "| " CYN "%s" WHT " ]\n",
                                is_new, i + 1, is_new, analecta["subject"],
                                analecta["author_name"] + "-" + analecta["author_id"],
                                ctime(analecta["time"])[0..9], analecta["board"]);
        }
        return info;
}

// �Ķ���ѡ
string read_analecta(int year, mapping analecta, int i, object me)
{
        string info;
        string content;

        info = sprintf(CYN " [" WHT "%3d" CYN "] %-36s "
                       WHT "%15s [ " CYN "%s " WHT "|" CYN
                       " %s" WHT " ]\n\n",
                       i, analecta["subject"],
                       analecta["author_name"] + "-" + analecta["author_id"],
                       ctime(analecta["time"])[0..9], analecta["board"]);
        content = analecta["content"];
        if (! stringp(content) ||
            content == "")
                info += CYN "�������κ����ݡ�\n" NOR;
        else
                info += CYN + content + NOR;

        if (analecta["add_time"] > me->query("analecta_last_read/" + year))
                me->set("analecta_last_read/" + year, analecta["add_time"]);

        return info;
}

// ��ѡ����
int sort_analectas(mapping a1, mapping a2) { return (a1["add_time"] - a2["add_time"]); }

// ɸѡ��ѡ
int filter_analectas(mapping analecta, int time) { return (analecta["add_time"] > time); }

int help(object me)
{
	write(@HELP
ָ���ʽ : wenxuan [ [ ��� ] <���> ]
                    [ add <�������> [ from <���԰�> ] ]
                    [ del <���> <���> ]
                    [ new [ ��� ] ]
                    [ convert <Ŀ¼> ]

��ָ���ṩ��ѡ���Ķ������Ӻ�ɾ�����Ķ�ʱ����������ѡ����Ҫ
ָ������⣬�����Ķ�Ҫָ����ȡ� �����Ķ� 2000 ��� 3 ����
ѡ�������� wenxuan 2000 3�� ʹ�� new ���������Ķ�����δ��
��������ѡ��
��ʦ����ʹ�� new �����������ѡ��del ������ɾ����ѡ�� ɾ��
��ѡ��Ҫָ����Ⱥ���ţ������ѡ�����ָ�����ڷ�������԰�
ID���磺
    ��ջ���԰�(board) [ 4 ������ ]
ʹ�� wenxuan add 1 from board���Ϳ��԰ѿ�ջ���԰�ĵ�һ��
������ӵ��������ѡ�С�

����ʹ�� convert������ָ��Ŀ¼�����еľɰ汾��ѡ����ת����
�°汾�����ݡ�
HELP);
    return 1;
}